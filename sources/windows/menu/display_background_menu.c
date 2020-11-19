/*
** EPITECH PROJECT, 2019
** display_background_menu.c
** File description:
** display menu background
*/

#include "rpg.h"

void parrallax_cloud(game_t *game, img_t *img, float speed)
{
    if ((*img).pos.x >= 1920)
        (*img).pos.x = -1920;
    (*img).pos.x += speed * 0.5;
    sfSprite_setPosition((*img).sprite, (*img).pos);
    sfRenderWindow_drawSprite(game->window, (*img).sprite, NULL);
}

void b_menu(game_t *game)
{
    sfSprite_setPosition(game->menu.image[7].sprite, game->menu.image[7].pos);
    sfRenderWindow_drawSprite(game->window, game->menu.image[7].sprite, NULL);
    sfSprite_setPosition(game->menu.image[8].sprite, \
v_pos(1350, 260 + game->menu.target * 150));
    display_next_anim(&game->menu.image[8], game, 100);
}

void b_usage(game_t *game)
{
    for (int i = 13; i < 19; i++)
        display_element(game, game->menu.image[i]);
    sfSprite_setPosition(game->menu.image[8].sprite, \
v_pos(50, 860));
    display_next_anim(&game->menu.image[8], game, 100);
}

void b_load(game_t *game)
{
    if (game->menu.target == 12) {
        sfSprite_setScale(game->menu.image[8].sprite, v_pos(2, 2));
        sfSprite_setPosition(game->menu.image[8].sprite, \
v_pos(game->menu.image[game->menu.target].pos.x - 50, \
game->menu.image[game->menu.target].pos.y + 10));
    }
    else {
        sfSprite_setScale(game->menu.image[8].sprite, v_pos(4, 4));
        sfSprite_setPosition(game->menu.image[8].sprite, \
v_pos(game->menu.image[game->menu.target].pos.x - 120, \
game->menu.image[game->menu.target].pos.y + 65));
    }
    display_next_anim(&game->menu.image[8], game, 100);
}

void display_background_menu(game_t *game)
{
    display_next_anim(&game->menu.image[4], game, 4000);
    for (int i = 5; i < 7; i++)
        parrallax_cloud(game, &game->menu.image[i], 1);
    if (game->scene == 0)
        b_menu(game);
    if (game->scene == 1)
        b_usage(game);
    if (game->scene == 3 || game->scene == 4)
        b_load(game);
}
