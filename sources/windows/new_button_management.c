/*
** EPITECH PROJECT, 2019
** new_button_management
** File description:
** new_button_management
*/

#include "rpg.h"

void new_button_save_max(game_t *game, int i)
{
    if (i == 11) {
        if (SOUND) {
            sfMusic_stop(game->sound[0]);
            sfMusic_play(game->sound[2]);
        }
        game->rpg->chain_list = ini_chain_list();
        game->scene = 2;
    }
    if (i == 12) {
        game->menu.target = 0;
        game->scene = 0;
    }
}

void new_button_management(game_t *game, int i)
{
    if (i == 9) {
        if (SOUND) {
            sfMusic_stop(game->sound[0]);
            sfMusic_play(game->sound[2]);
        }
        game->rpg->chain_list = ini_chain_list();
        game->scene = 2;
    }
    if (i == 10) {
        if (SOUND) {
            sfMusic_stop(game->sound[0]);
            sfMusic_play(game->sound[2]);
        }
        game->rpg->chain_list = ini_chain_list();
        game->scene = 2;
    }
    new_button_save_max(game, i);
}
