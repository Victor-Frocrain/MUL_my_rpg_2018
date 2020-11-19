/*
** EPITECH PROJECT, 2019
** animate_player
** File description:
** animate_player
*/

#include "../../include/rpg.h"

void move_rain(game_t *game, float speed)
{
    for (int i = 0; i < NB_PIXEL; i++)
        game->pixel[i]->pos.x += speed;
}

void animate_player(game_t *game)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->rpg->player->walk)) < 90)
        return;
    if (game->rpg->player->image->rect.left < 270 - 270 / 9)
        game->rpg->player->image->rect.left += 270 / 9;
    else
        game->rpg->player->image->rect.left = 0;
    sfClock_restart(game->rpg->player->walk);
}

bool turn_vertical(game_t *game, int key)
{
    if (key == sfKeyZ && sfKeyboard_isKeyPressed(sfKeyS) == false &&
    sfKeyboard_isKeyPressed(sfKeyDown) == false) {
        game->rpg->map->begin->pos.y += 2;
        return (true);
    }
    if (key == sfKeyS && sfKeyboard_isKeyPressed(sfKeyZ) == false &&
    sfKeyboard_isKeyPressed(sfKeyUp) == false) {
        game->rpg->map->begin->pos.y -= 2;
        return (true);
    }
    return (false);
}

void turn_horizontal(game_t *game, int key)
{
    if (key == sfKeyQ && sfKeyboard_isKeyPressed(sfKeyD) == false &&
    sfKeyboard_isKeyPressed(sfKeyRight) == false) {
        move_rain(game, 2);
        game->rpg->map->begin->pos.x += 2;
    }
    if (key == sfKeyD && sfKeyboard_isKeyPressed(sfKeyQ) == false &&
    sfKeyboard_isKeyPressed(sfKeyLeft) == false) {
        move_rain(game, -2);
        game->rpg->map->begin->pos.x -= 2;
    }
}

void turn_player(game_t *game, int key)
{
    if (turn_vertical(game, key) == false)
        turn_horizontal(game, key);
    animate_player(game);
}
