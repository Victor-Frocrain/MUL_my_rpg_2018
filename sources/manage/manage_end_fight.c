/*
** EPITECH PROJECT, 2019
** manage_end_fight
** File description:
** manage_end_fight
*/

#include "rpg.h"

void manage_game_over(game_t *game)
{
    if (game->rpg->is_game_over) {
        if (SOUND) {
            sfMusic_stop(game->sound[1]);
            sfMusic_play(game->sound[0]);
        }
        destroy_chain_list(game->rpg->chain_list);
        destroy_fight(game->rpg->fight);
        game->rpg->fight = NULL;
        game->rpg->chain_list = NULL;
        game->scene = 0;
    }
}

void manage_end_fight(game_t *game)
{
    game->rpg->is_fighting = is_end(game);
    if (!game->rpg->is_fighting) {
        game->rpg->pnj->is_boss = false;
        if (SOUND && !game->rpg->is_game_over) {
            sfMusic_stop(game->sound[1]);
            sfMusic_play(game->sound[2]);
        }
        if (!game->rpg->is_game_over) {
            gave_rewards_to_players(game);
            destroy_enemy(game->rpg->chain_list);
        }
    }
    manage_game_over(game);
}
