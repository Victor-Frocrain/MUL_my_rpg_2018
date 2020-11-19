/*
** EPITECH PROJECT, 2019
** curse_event.c
** File description:
** manage curse event and call manage func
*/

#include "rpg.h"

void curse_event(game_t *game, bool *is_key_pressed, \
void (*func)(game_t *game, int key))
{
    for (int i = 0; i < 4; i++) {
        if (sfKeyboard_isKeyPressed(i + sfKeyLeft) && !is_key_pressed[i])
            is_key_pressed[i] = true;
        if (!sfKeyboard_isKeyPressed(i + sfKeyLeft) && is_key_pressed[i]) {
            is_key_pressed[i] = false;
            func(game, i + sfKeyLeft);
        }
    }
}
