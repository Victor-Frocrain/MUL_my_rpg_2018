/*
** EPITECH PROJECT, 2019
** destroy_game.c
** File description:
** destroy_game.c
*/

#include "rpg.h"

void destroy_game(game_t *game)
{
    for (int i = 0; i < NB_SOUND; i++)
        sfMusic_destroy(game->sound[i]);
    if (game->sound)
        free(game->sound);
    if (game->rpg)
        destroy_rpg(game);
    destroy_menu(game);
    if (game->is_key_pressed)
        free(game->is_key_pressed);
}
