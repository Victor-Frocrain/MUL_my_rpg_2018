/*
** EPITECH PROJECT, 2019
** init_files
** File description:
** init_files
*/

#include "../../include/rpg.h"

void init_files(game_t *game)
{
    game->rpg->map->files[0] = my_strcpy("maps/world1");
    game->rpg->map->files[1] = my_strcpy("maps/home2");
    game->rpg->map->files[2] = my_strcpy("maps/home1");
    game->rpg->map->files[3] = my_strcpy("maps/inn");
    game->rpg->map->files[4] = my_strcpy("maps/church");
    game->rpg->map->files[5] = my_strcpy("maps/cave");
    game->rpg->map->files[6] = NULL;
}
