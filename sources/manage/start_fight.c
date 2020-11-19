/*
** EPITECH PROJECT, 2019
** start_fight.c
** File description:
** engage a fight
*/

#include "rpg.h"

bool manage_enemy_creation(game_t *game, int *enemy_count)
{
    int random = rand() / (RAND_MAX / 100 + 1);

    if (random > 25)
        (*enemy_count)++;
    if (random > 75)
        (*enemy_count)++;
    for (int i = 0; i < *enemy_count; i++)
        if (!create_enemy(game))
            return (false);
    return (true);
}

bool creating_enemy_scene(game_t *game, int enemy_count)
{
    fight_scene_t *scene = malloc(sizeof(fight_scene_t));
    int i = 0;

    if (!scene || !(scene->av = malloc(sizeof(char *) * (enemy_count + 1))) ||
        !(scene->next = malloc(sizeof(fight_scene_t *) * enemy_count)))
        return (false);
    for (enemy_t *enemy = game->rpg->chain_list->e_begin;
    enemy; enemy = enemy->next, i++) {
        scene->next[i] = NULL;
        scene->av[i] = enemy->stat.name;
    }
    scene->av[enemy_count] = NULL;
    scene->name = "Attack";
    scene->target = 0;
    game->rpg->fight->enemy_scene = scene;
    game->rpg->fight->scene->next[0] = game->rpg->fight->enemy_scene;
    scene->prev = game->rpg->fight->first_scene;
    return (true);
}

order_t fill_order(bool is_first, player_t *player, enemy_t *enemy)
{
    order_t order;
    int random = (enemy && player)?rand() / (RAND_MAX / 2):-1;

    order.is_ally = (random == 0 || (random == -1 && !player))?false:true;
    if (!order.is_ally)
        order.stat = &enemy->stat;
    else
        order.stat = &player->stat;
    order.is_first = is_first;
    return (order);
}

order_t *ini_order(chain_list_t *chain_list)
{
    player_t *player = chain_list->p_begin;
    enemy_t *enemy = chain_list->e_begin;
    int nb_entity = chain_list->e_nb + chain_list->p_nb;
    order_t *order = malloc(sizeof(order_t) * nb_entity);

    chain_list->nb_entity = nb_entity;
    if (!order)
        return (NULL);
    for (int i = 0; i < nb_entity; i++) {
        order[i] = fill_order(i == 0, player, enemy);
        if (order[i].is_ally)
            player = player->next;
        else
            enemy = enemy->next;
    }
    return (order);
}

bool engage_fight(game_t *game)
{
    int enemy_count = 1;

    if (!game->rpg->fight)
        if (!(game->rpg->fight = ini_fight()))
            return (true);
    game->rpg->fight->turn = 0;
    if (!manage_enemy_creation(game, &enemy_count))
        return (true);
    if (!creating_enemy_scene(game, enemy_count))
        return (true);
    if (!(game->rpg->fight->order = ini_order(game->rpg->chain_list)))
        return (true);
    game->rpg->is_fighting = true;
    if (!game->rpg->fight->player_scene)
        if (ini_player_fight_scene(game->rpg))
            return (true);
    if (game->rpg->fight->order->is_ally)
        create_spell_scene(game, game->rpg->fight->order->stat);
    else
        game->rpg->fight->scene->next[1] = NULL;
    return (false);
}
