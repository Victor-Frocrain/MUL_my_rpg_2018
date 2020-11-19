/*
** EPITECH PROJECT, 2019
** destroy_enemy.c
** File description:
** destroying enemy ressources
*/

#include "../../include/rpg.h"

bool next_turn(game_t *game)
{
    order_t *order = game->rpg->fight->order;
    int *i = &game->rpg->fight->turn;
    int nb_entity = game->rpg->chain_list->nb_entity;

    do {
        if (*i >= nb_entity - 1)
            *i = 0;
        else
            (*i)++;
    } while (order[*i].stat->is_dead);
    if (order[*i].is_ally)
        return (!create_spell_scene(game, order[*i].stat));
    return (false);
}

void destroy_enemy(chain_list_t *chain_list)
{
    enemy_t *enemy = chain_list->e_begin;

    for (enemy_t *en = chain_list->e_begin; enemy; enemy = en) {
        en = en->next;
        free(enemy->stat.name);
        free(enemy);
    }
    chain_list->e_begin = NULL;
    chain_list->e_end = NULL;
    chain_list->e_nb = 0;
}

bool is_same_stat(stat_t stat1, stat_t stat2)
{
    if (stat1.life != stat2.life)
        return (false);
    if (stat1.max_dmg != stat2.max_dmg)
        return (false);
    if (stat1.max_life != stat2.max_life)
        return (false);
    if (stat1.name != stat2.name)
        return (false);
    if (stat1.min_dmg != stat2.min_dmg)
        return (false);
    return (true);
}

bool remove_enemy(game_t *game, enemy_t *enemy)
{
    int nb_arg = count_arg(game->rpg->fight->scene->av);
    char **av = malloc(sizeof(char *) * (nb_arg + 1));
    int j = 0;

    if (!av)
        return (false);
    for (int i = 0; j < nb_arg; i++)
        if (i != game->rpg->fight->scene->target)
            av[j++] = game->rpg->fight->scene->av[i];
    game->rpg->fight->scene->av = av;
    game->rpg->fight->enemy_scene->av = av;
    game->rpg->chain_list->e_nb--;
    enemy->stat.is_dead = true;
    enemy->stat.life = 0;
    return (true);
}
