/*
** EPITECH PROJECT, 2019
** destroy menu
** File description:
** destroy menu function
*/

#include "rpg.h"

void destroy_menu(game_t *game)
{
    for (int i = 0; i < MENU_IMG; i++){
        sfTexture_destroy(game->menu.image[i].texture);
        sfSprite_destroy(game->menu.image[i].sprite);
    }
    sfFont_destroy(game->menu.font);
    sfText_destroy(game->menu.text);
}
