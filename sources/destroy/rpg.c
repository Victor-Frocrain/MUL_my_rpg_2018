/*
** EPITECH PROJECT, 2019
** destroy_rpg.c
** File description:
** destroying rpg ressources
*/

#include "rpg.h"

void destroy_rpg(game_t *game)
{
    if (game->rpg->chain_list)
        destroy_chain_list(game->rpg->chain_list);
    if (game->rpg->fight)
        destroy_fight(game->rpg->fight);
    free(game->rpg);
    game->rpg = NULL;
}
