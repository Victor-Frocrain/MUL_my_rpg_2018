/*
** EPITECH PROJECT, 2019
** load
** File description:
** load game menu
*/

#include "rpg.h"

bool load_mouse_press(game_t *game, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->menu.is_pressed = true;
        if (i == 12)
            game->menu.image[i].rect = ini_rect(120, 0, 60, 15);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && game->menu.is_pressed) {
        game->menu.is_pressed = false;
        load_button_management(game, i);
    }
    return (game->menu.is_pressed);
}

void manage_load_hud(game_t *game, int key)
{
    if (key == sfKeyUp || key == sfKeyDown)
        (key == sfKeyUp) ? game->menu.target--: game->menu.target++;
    (game->menu.target < 9) ? game->menu.target = 12:0;
    (game->menu.target >= 13) ? game->menu.target = 9:0;
    if (key == sfKeyRight)
        load_button_management(game, game->menu.target);
}

void get_load_mouse_pos(game_t *game, sfVector2f mouse2, int i)
{
    if (i == 12) {
        if (test_rect(game->menu.image, mouse2, i, MENU_IMG)) {
            game->menu.target = i;
            game->menu.pos = i;
            game->menu.image[i].rect = ini_rect(60, 0, 60, 15);
            game->menu.is_pressed = load_mouse_press(game, i);
        } else if (i == -1 || !test_rect(game->menu.image, mouse2, \
game->menu.pos, MENU_IMG)) {
            game->menu.pos = -1;
            game->menu.is_pressed = false;
        }
    } else
    if (test_rect_fix_rect(game->menu.image, mouse2, i, MENU_IMG)) {
        (game->menu.target = i, game->menu.pos = i);
        game->menu.is_pressed = load_mouse_press(game, i);
    } else if (i == -1 || !test_rect_fix_rect(game->menu.image, mouse2, \
game->menu.pos, MENU_IMG)) {
        game->menu.pos = -1;
        game->menu.is_pressed = false;
    }
}

void load(game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse2 = {mouse.x, mouse.y};

    curse_event(game, game->is_key_pressed, manage_load_hud);
    display_background_menu(game);
    for (int i = 9; i < 13; i++) {
        refresh_load(game);
        text_save(game);
        get_load_mouse_pos(game, mouse2, i);
        display_element(game, game->menu.image[i]);
    }
}
