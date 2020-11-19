/*
** EPITECH PROJECT, 2019
** pause
** File description:
** pause function
*/

#include "rpg.h"

void display_pause(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        game->menu.is_pressed = true;
    if (!sfKeyboard_isKeyPressed(sfKeySpace) && game->menu.is_pressed) {
        game->menu.is_pressed = false;
        game->pause = !game->pause;
    }
    if (game->pause) {
        display_element(game, game->menu.image[19]);
        manage_sparks(game);
        display_element(game, game->menu.image[20]);
    }
}
