/*
** EPITECH PROJECT, 2019
** destroy_chain_list.c
** File description:
** destroying chain list ressources
*/

#include "rpg.h"

void destroy_chain_list(chain_list_t *chain_list)
{
    destroy_player(chain_list);
    destroy_enemy(chain_list);
    free(chain_list);
}
