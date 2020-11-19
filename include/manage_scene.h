/*
** EPITECH PROJECT, 2019
** manage_scene.h
** File description:
** manage_scene.h
*/

#ifndef MANAGE_SCENE_H
#define MANAGE_SCENE_H

#include "rpg.h"

/* Menu_window */
void menu_button_management(game_t *game, int i);
bool menu_mouse_press(game_t *game, bool is_pressed, int i);
void menu_window(game_t *game);
/* Menu_window */
void game_window(game_t *game);
void usage_window(game_t *game);
void new(game_t *game);
void load(game_t *game);

typedef struct manage_scene_s {
    void (*func)(game_t *game);
}manage_scene_t;

const manage_scene_t scene[5] = {
    {menu_window},
    {usage_window},
    {game_window},
    {new},
    {load}
};

#endif /* MANAGE_SCENE_H */
