/*
** EPITECH PROJECT, 2019
** load_button_management
** File description:
** load_button_management
*/

#include "rpg.h"

void load_button_high(game_t *game, int i)
{
    if (i == 11 && my_get_str_fd("save3", 1) && game->already_done == 0) {
        game->already_done++;
        if (SOUND) {
            sfMusic_stop(game->sound[0]);
            sfMusic_play(game->sound[2]);
        }
        load_save(game, "save3");
        game->scene = 2;
    }
    if (i == 12) {
        game->menu.target = 1;
        game->scene = 0;
    }
}

void load_button_management(game_t *game, int i)
{
    sfSprite_setScale(game->menu.image[8].sprite, v_pos(2, 2));
    if (i == 9 && my_get_str_fd("save1", 1) && game->already_done == 0) {
        game->already_done++;
        if (SOUND) {
            sfMusic_stop(game->sound[0]);
            sfMusic_play(game->sound[2]);
        }
        load_save(game, "save1");
        game->scene = 2;
    }
    if (i == 10 && my_get_str_fd("save2", 1) && game->already_done == 0) {
        game->already_done++;
        if (SOUND) {
            sfMusic_stop(game->sound[0]);
            sfMusic_play(game->sound[2]);
        }
        load_save(game, "save2");
        game->scene = 2;
    }
    load_button_high(game, i);
}
