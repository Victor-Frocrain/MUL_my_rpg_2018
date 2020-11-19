/*
** EPITECH PROJECT, 2019
** manage_collisions
** File description:
** manage_collisions
*/

#include "../../include/rpg.h"

bool check_vertical(game_t *game, int i, int j, int move)
{
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds
    (game->rpg->player->image->sprite);

    if (move == sfKeyS && player.y + bounds.height > map.y + 50 * i - 2 &&
        player.y < map.y + 50 * i + 50 - 2 &&
        player.x <= map.x + 50 * j + 50 &&
        player.x + bounds.width >= map.x + 50 * j)
        return (false);
    if (move == sfKeyZ && player.y < map.y + 50 * i + 50 + 2 &&
        player.y + bounds.height > map.y + 50 * i + 2 &&
        player.x <= map.x + 50 * j + 50 &&
        player.x + bounds.width >= map.x + 50 * j)
        return (false);
    return (true);
}

bool check_horizontal(game_t *game, int i, int j, int move)
{
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = sfSprite_getGlobalBounds
    (game->rpg->player->image->sprite);

    if (move == sfKeyD && player.x + bounds.width > map.x + 50 * j - 3 &&
        player.x < map.x + 50 * j + 50 - 3 &&
        player.y + bounds.height > map.y + 50 * i &&
        player.y < map.y + 50 * i + 50)
        return (false);
    if (move == sfKeyQ && player.x < map.x + 50 * j + 50 + 3 &&
        player.x > map.x + 50 * j + 3 &&
        player.y + bounds.height > map.y + 50 * i &&
        player.y < map.y + 50 * i + 50)
        return (false);
    return (true);
}

bool manage_collisions(game_t *game, int move)
{
    int j = 0;
    int len = 0;

    for (int i = 0; game->rpg->map->begin->map[i] &&
    game->rpg->map->begin->map[i][j];) {
        if (j == 0)
            len = my_strlen(game->rpg->map->begin->map[i]);
        if (detect_block(game, i, j) &&
            (check_vertical(game, i, j, move) == false ||
            check_horizontal(game, i, j, move) == false))
            return (false);
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    return (true);
}
