/*
** EPITECH PROJECT, 2019
** display_extend_map
** File description:
** display_extend_map
*/

#include "rpg.h"

void display_walls(game_t *game, char c, sfVector2f pos)
{
    if (c == 'x') {
        sfSprite_setPosition(game->rpg->map->elem[house_wall]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[house_wall]->sprite, sfFalse);
    }
}

void display_in_cave(game_t *game, char c, sfVector2f pos)
{
    if (c == 's') {
        sfSprite_setPosition(game->rpg->map->elem[stalagmite]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[stalagmite]->sprite, sfFalse);
    }
    if (c == 'w') {
        sfSprite_setPosition(game->rpg->map->elem[water]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[water]->sprite, sfFalse);
    }
    if (c == 'r') {
        sfSprite_setPosition(game->rpg->map->elem[road]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[road]->sprite, sfFalse);
    }
    display_walls(game, c, pos);
}

void display_in_house(game_t *game, char c, sfVector2f pos)
{
    if (c == 'b') {
        pos.x -= 50;
        sfSprite_setPosition(game->rpg->map->elem[bed]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[bed]->sprite, sfFalse);
    }
    if (c == 't') {
        pos.x -= 50;
        sfSprite_setPosition(game->rpg->map->elem[table]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[table]->sprite, sfFalse);
    }
    if (c == 'S') {
        sfSprite_setPosition(game->rpg->map->elem[stool]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[stool]->sprite, sfFalse);
    }
    display_in_cave(game, c, pos);
}
