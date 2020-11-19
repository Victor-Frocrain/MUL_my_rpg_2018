/*
** EPITECH PROJECT, 2019
** display_map
** File description:
** display_map
*/

#include "rpg.h"

void display_blocks(game_t *game, char c, sfVector2f pos)
{
    if (c == 'X') {
        sfSprite_setPosition(game->rpg->map->elem[bloc]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[bloc]->sprite, sfFalse);
    }
    if (c == 'W') {
        sfSprite_setPosition(game->rpg->map->elem[c_wall]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[c_wall]->sprite, sfFalse);
    }
    if (c == 'B') {
        sfSprite_setPosition(game->rpg->map->elem[chair]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[chair]->sprite, sfFalse);
    }
}

void display_elem(game_t *game, char c, sfVector2f pos)
{
    if (c == 'G') {
        sfSprite_setPosition(game->rpg->map->elem[grass2]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[grass2]->sprite, sfFalse);
    }
    if (c == 'V') {
        sfSprite_setPosition(game->rpg->map->elem[vendor]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[vendor]->sprite, sfFalse);
    }
    if (c == 'I') {
        sfSprite_setPosition(game->rpg->map->elem[innkeeper]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[innkeeper]->sprite, sfFalse);
    }
    display_boss(game, c, pos);
    display_blocks(game, c, pos);
    display_in_house(game, c, pos);
}

void display_height_elem(game_t *game, char **map)
{
    sfVector2f pos = {0, 0};

    for (int i = 0, j = 0, len = 0; map && map[i] && map[i][j];) {
        pos.x = (float)(j * 50) + game->rpg->map->begin->pos.x;
        pos.y = (float)(i * 50) + game->rpg->map->begin->pos.y;
        if (j == 0)
            len = my_strlen(map[i]);
        display_trees(game, map[i][j], pos);
        display_church(game, map[i][j], pos);
        manage_pnj(game, i, j, map);
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    manage_particles(game);
    display_dial(game, game->rpg->pnj->text);
}

int display_ground(game_t *game, sfVector2f pos)
{
    switch (game->rpg->map->begin->type) {
    case (0):
        sfSprite_setPosition(game->rpg->map->elem[grass]->sprite, pos);
        return (grass);
    case (1):
        sfSprite_setPosition(game->rpg->map->elem[g_church]->sprite, pos);
        return (g_church);
    case (2):
        sfSprite_setPosition(game->rpg->map->elem[g_cave]->sprite, pos);
        return (g_cave);
    case (3):
        sfSprite_setPosition(game->rpg->map->elem[house_ground]->sprite, pos);
        return (house_ground);
    default:
        break;
    }
    return (grass);
}

void display_map(game_t *game, char **map)
{
    sfVector2f pos = {0, 0};

    for (int i = 0, j = 0, len = 0; map && map[i] && map[i][j];) {
        pos.x = (float)(j * 50) + game->rpg->map->begin->pos.x;
        pos.y = (float)(i * 50) + game->rpg->map->begin->pos.y;
        if (j == 0)
            len = my_strlen(map[i]);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[display_ground(game, pos)]->sprite, sfFalse);
        display_elem(game, map[i][j], pos);
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    sfRenderWindow_drawSprite(game->window,
    game->rpg->player->image->sprite, sfFalse);
    display_height_elem(game, map);
}
