/*
** EPITECH PROJECT, 2019
** refresh
** File description:
** refresh function
*/

#include "rpg.h"

void refresh_menu(game_t *game)
{
    for (int a = 0; a < 4; a++)
        game->menu.image[a].rect = ini_rect(0, 0, 60, 15);
    if (game->menu.pos == -1)
        game->menu.image[game->menu.target].rect = ini_rect(60, 0, 60, 15);
    if (game->is_key_pressed[1])
        game->menu.image[game->menu.target].rect = ini_rect(120, 0, 60, 15);
}

void refresh_usage(game_t *game)
{
    for (int a = 12; a < 13; a++)
        game->menu.image[a].rect = ini_rect(0, 0, 60, 15);
    if (game->menu.pos == -1)
        game->menu.image[game->menu.target].rect = ini_rect(60, 0, 60, 15);
    if (game->is_key_pressed[1])
        game->menu.image[game->menu.target].rect = ini_rect(120, 0, 60, 15);
    print_text_menu(game, "Move forward", v_pos(1050, 100), 40);
    print_text_menu(game, "Move backward", v_pos(1050, 225), 40);
    print_text_menu(game, "Move left", v_pos(1050, 350), 40);
    print_text_menu(game, "Move right", v_pos(1050, 475), 40);
    print_text_menu(game, "Display player inventory", v_pos(1050, 600), 40);
    print_text_menu(game, "Display pause menu", v_pos(1050, 725), 40);
}

void refresh_new(game_t *game)
{
    game->menu.image[12].rect = ini_rect(0, 0, 60, 15);
    if (game->menu.target == 12) {
        if (game->menu.pos == -1)
            game->menu.image[game->menu.target].rect = ini_rect(60, 0, 60, 15);
        if (game->is_key_pressed[1])
            game->menu.image[game->menu.target].rect = ini_rect(120, 0, 60, 15);
    }
}

void refresh_load(game_t *game)
{
    game->menu.image[12].rect = ini_rect(0, 0, 60, 15);
    if (game->menu.target == 12) {
        if (game->menu.pos == -1)
            game->menu.image[game->menu.target].rect = ini_rect(60, 0, 60, 15);
        if (game->is_key_pressed[1])
            game->menu.image[game->menu.target].rect = ini_rect(120, 0, 60, 15);
    }
}
