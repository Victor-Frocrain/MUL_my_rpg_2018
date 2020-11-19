/*
** EPITECH PROJECT, 2019
** destroy_player.c
** File description:
** destroy player ressources
*/

#include "rpg.h"

void destroy_player(chain_list_t *chain_list)
{
    player_t *player = chain_list->p_begin;

    for (player_t *play = player; player; player = play) {
        play = play->next;
        free(player);
    }
    chain_list->p_begin = NULL;
    chain_list->p_end = NULL;
}
