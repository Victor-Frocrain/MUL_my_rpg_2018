/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** manage_turn.c
*/

#include "rpg.h"

bool manage_ai(game_t *game)
{
    stat_t *enemy = game->rpg->fight->order->stat;
    player_t *player = game->rpg->chain_list->p_begin;
    int decision = 0;
    int dmg = (enemy->max_dmg != enemy->min_dmg)?(rand() / (RAND_MAX / \
(enemy->max_dmg - enemy->min_dmg)) + enemy->min_dmg):enemy->max_dmg;
    bool is_error = false;

    if (game->rpg->chain_list->p_nb != 1)
        decision = rand() / (RAND_MAX / game->rpg->chain_list->p_nb);
    for (int i = 0; i != decision && player; player = player->next, i++);
    player->stat.life -= dmg;
    if (player->stat.life <= 0) {
        player->stat.is_dead = true;
        game->rpg->chain_list->p_nb--;
        player->stat.life = 0;
        is_error = ini_player_fight_scene(game->rpg);
    }
    if (!is_error)
        is_error = next_turn(game);
    return (is_error);
}

void manage_turn(game_t *game)
{
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock));

    if (game->rpg->fight->order[game->rpg->fight->turn].is_ally) {
        curse_event(game, game->is_key_pressed, manage_hud_move);
        game->rpg->fight->tempo = time;
    } else if (time > game->rpg->fight->tempo + 2000) {
        manage_ai(game);
        game->rpg->fight->tempo = time;
    }
}

void display_turn(game_t *game)
{
    order_t *order = game->rpg->fight->order;
    int turn = game->rpg->fight->turn;
    int count = 1;

    my_putchar('\n');
    for (int i = turn; i < game->rpg->chain_list->nb_entity; i++)
        if (!order[i].stat->is_dead) {
            my_printf("%d: %s\n", count, order[i].stat->name);
            count++;
        }
    for (int i = 0; i < turn; i++)
        if (!order[i].stat->is_dead) {
            my_printf("%d: %s\n", count, order[i].stat->name);
            count++;
        }
}
