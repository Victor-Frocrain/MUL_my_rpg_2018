/*
** EPITECH PROJECT, 2019
** display_win
** File description:
** display_win
*/

#include "rpg.h"

void display_win(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyE))
        sfRenderWindow_close(game->window);
    sfRenderWindow_drawSprite(game->window, game->rpg->back->sprite, NULL);
    sfRenderWindow_drawText(game->window, game->rpg->congrats, NULL);
}
