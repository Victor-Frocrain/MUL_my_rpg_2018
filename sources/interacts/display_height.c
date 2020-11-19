/*
** EPITECH PROJECT, 2019
** display_height
** File description:
** display_height
*/

#include "rpg.h"

void display_trees(game_t *game, char c, sfVector2f pos)
{
    pos.x -= 50;
    pos.y -= 100;
    if (c == 'T') {
        sfSprite_setPosition(game->rpg->map->elem[tree]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[tree]->sprite, sfFalse);
    }
    if (c == 'F') {
        sfSprite_setPosition(game->rpg->map->elem[fir]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[fir]->sprite, sfFalse);
    }
}

void display_in_church(game_t *game, char c, sfVector2f pos)
{
    pos.x -= 300;
    pos.y -= 400;
    if (c == 'c') {
        sfSprite_setPosition(game->rpg->map->elem[c_back]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[c_back]->sprite, sfFalse);
    }
}

void display_house(game_t *game, char c, sfVector2f pos)
{
    pos.x -= 300;
    pos.y -= 250;
    if (c == 'H') {
        sfSprite_setPosition(game->rpg->map->elem[house1]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[house1]->sprite, sfFalse);
    }
    if (c == 'h') {
        sfSprite_setPosition(game->rpg->map->elem[house2]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[house2]->sprite, sfFalse);
    }
    if (c == 'i') {
        pos.x -= 150;
        pos.y -= 100;
        sfSprite_setPosition(game->rpg->map->elem[inn]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[inn]->sprite, sfFalse);
    }
}

void display_church(game_t *game, char c, sfVector2f pos)
{
    if (c == 'C') {
        pos.x -= 300;
        pos.y -= 800;
        sfSprite_setPosition(game->rpg->map->elem[church]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[church]->sprite, sfFalse);
    }
    if (c == 'f') {
        sfSprite_setPosition(game->rpg->map->elem[fog]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[fog]->sprite, sfFalse);
    }
    display_in_church(game, c, pos);
    display_house(game, c, pos);
}
