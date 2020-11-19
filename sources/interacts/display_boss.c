/*
** EPITECH PROJECT, 2019
** display_boss
** File description:
** display_boss
*/

#include "rpg.h"

void display_boss(game_t *game, char c, sfVector2f pos)
{
    if (c == 'D') {
        sfSprite_setPosition(game->rpg->map->elem[map_daemon]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[map_daemon]->sprite, sfFalse);
    }
    if (c == 'd' && game->rpg->pnj->dragon_unlocked) {
        sfSprite_setPosition(game->rpg->map->elem[dragon]->sprite, pos);
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[dragon]->sprite, sfFalse);
    }
}
