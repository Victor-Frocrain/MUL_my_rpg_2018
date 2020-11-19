/*
** EPITECH PROJECT, 2019
** detect_block
** File description:
** detect_block
*/

#include "rpg.h"

bool detect_block3(game_t *game, int i, int j)
{
    switch (game->rpg->map->begin->map[i][j]) {
    case ('b'):
        return (true);
    case ('t'):
        return (true);
    case ('S'):
        return (true);
    case ('s'):
        return (true);
    case ('w'):
        return (true);
    case ('x'):
        return (true);
    default:
        break;
    }
    return (false);
}

bool detect_block2(game_t *game, int i, int j)
{
    switch (game->rpg->map->begin->map[i][j]) {
    case ('W'):
        return (true);
    case ('B'):
        return (true);
    case ('I'):
        return (true);
    case ('H'):
        return (true);
    case ('h'):
        return (true);
    case ('i'):
        return (true);
    default:
        break;
    }
    return (detect_block3(game, i, j));
}

bool detect_block(game_t *game, int i, int j)
{
    switch (game->rpg->map->begin->map[i][j]) {
    case ('X'):
        return (true);
    case ('F'):
        return (true);
    case ('T'):
        return (true);
    case ('V'):
        return (true);
    case ('E'):
        return (true);
    case ('C'):
        return (true);
    case ('c'):
        return (true);
    default:
        break;
    }
    return (detect_block2(game, i, j));
}
