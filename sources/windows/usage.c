/*
** EPITECH PROJECT, 2019
** w_usage.c
** File description:
** w_usage.c
*/

#include "rpg.h"

void usage_button_management(game_t *game, int i)
{
    if (i == 12) {
        game->menu.target = 2;
        game->scene = 0;
    }
}

bool usage_mouse_press(game_t *game, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->menu.is_pressed = true;
        game->menu.image[i].rect = ini_rect(120, 0, 60, 15);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && game->menu.is_pressed) {
        game->menu.is_pressed = false;
        usage_button_management(game, i);
    }
    return (game->menu.is_pressed);
}

void manage_usage_hud(game_t *game, int key)
{
    if (key == sfKeyUp || key == sfKeyDown)
        (key == sfKeyUp) ? game->menu.target--: game->menu.target++;
    (game->menu.target < 12) ? game->menu.target = 12:0;
    (game->menu.target >= 13) ? game->menu.target = 12:0;
    if (key == sfKeyRight)
        usage_button_management(game, game->menu.target);
}

void usage_window(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse2 = {mouse.x, mouse.y};

    curse_event(game, game->is_key_pressed, manage_usage_hud);
    display_background_menu(game);
    for (int i = 12; i < 13; i++) {
        refresh_usage(game);
        if (test_rect(game->menu.image, mouse2, i, MENU_IMG)) {
            game->menu.target = i;
            game->menu.pos = i;
            game->menu.image[i].rect = ini_rect(60, 0, 60, 15);
            game->menu.is_pressed = usage_mouse_press(game, i);
        } else if (i == -1 || !test_rect(game->menu.image, mouse2, \
game->menu.pos, MENU_IMG)) {
            game->menu.pos = -1;
            game->menu.is_pressed = false;
        }
        display_element(game, game->menu.image[i]);
    }
}
