/*
** EPITECH PROJECT, 2019
** manage_interacts
** File description:
** manage_interacts
*/

#include "../../include/rpg.h"

bool switch_prev(game_t *game, char c, int i, int j)
{
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds
    (game->rpg->player->image->sprite);

    if (c == 'P' && player.x + bounds.width > map.x + 50 * j &&
    player.x < map.x + 50 * j + 50 &&
    player.y + bounds.height > map.y + 50 * i &&
    player.y < map.y + 50 * i + 50) {
        if (game->rpg->map->begin->prev)
            game->rpg->map->begin = game->rpg->map->begin->prev;
        return (true);
    }
    return (false);
}

bool switch_next(game_t *game, char c, int i, int j)
{
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds
    (game->rpg->player->image->sprite);

    if (c >= '0' && c <= '9' && player.x + bounds.width > map.x + 50 * j &&
    player.x < map.x + 50 * j + 50 &&
    player.y + bounds.height > map.y + 50 * i &&
    player.y < map.y + 50 * i + 50) {
        if (game->rpg->map->begin->next[c - '0'])
            game->rpg->map->begin = game->rpg->map->begin->next[c - '0'];
        return (true);
    }
    return (switch_prev(game, c, i, j));
}

void manage_interacts(game_t *game)
{
    int j = 0;
    int len = 0;

    for (int i = 0; game->rpg->map->begin->map[i] &&
    game->rpg->map->begin->map[i][j];) {
        if (j == 0)
            len = my_strlen(game->rpg->map->begin->map[i]);
        if (switch_next(game, game->rpg->map->begin->map[i][j], i, j))
            return;
        go_fight(game, game->rpg->map->begin->map[i][j], i, j);
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
}
