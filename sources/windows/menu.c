/*
** EPITECH PROJECT, 2019
** menu_window.c
** File description:
** menu_window.c
*/

#include "rpg.h"

void menu_button_management(game_t *game, int i)
{
    if (i == 0) {
        game->menu.target = 12;
        game->scene = 3;
    }
    if (i == 1) {
        game->menu.target = 12;
        game->scene = 4;
    }
    if (i == 2) {
        game->menu.target = 12;
        game->scene = 1;
    }
    if (i == 3) {
        sfRenderWindow_close(game->window);
    }
}

bool menu_mouse_press(game_t *game, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->menu.is_pressed = true;
        game->menu.image[i].rect = ini_rect(120, 0, 60, 15);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && game->menu.is_pressed) {
        game->menu.is_pressed = false;
        menu_button_management(game, i);
    }
    return (game->menu.is_pressed);
}

void manage_menu_hud(game_t *game, int key)
{
    if (key == sfKeyUp || key == sfKeyDown)
        (key == sfKeyUp) ? game->menu.target--: game->menu.target++;
    (game->menu.target < 0) ? game->menu.target = 3:0;
    (game->menu.target >= 4) ? game->menu.target = 0:0;
    if (key == sfKeyRight)
        menu_button_management(game, game->menu.target);
}

void menu_window(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse2 = {mouse.x, mouse.y};

    curse_event(game, game->is_key_pressed, manage_menu_hud);
    display_background_menu(game);
    for (int i = 0; i < 4; i++) {
        refresh_menu(game);
        if (test_rect(game->menu.image, mouse2, i, MENU_IMG)) {
            game->menu.target = i;
            game->menu.pos = i;
            game->menu.image[i].rect = ini_rect(60, 0, 60, 15);
            game->menu.is_pressed = menu_mouse_press(game, i);
        } else if (i == -1 || !test_rect(game->menu.image, mouse2, \
game->menu.pos, MENU_IMG)) {
            game->menu.pos = -1;
            game->menu.is_pressed = false;
        }
        display_element(game, game->menu.image[i]);
    }
}
