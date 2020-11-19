/*
** EPITECH PROJECT, 2019
** chain_list.c
** File description:
** ini chain list enemy player
*/

#include "rpg.h"

chain_list_t *ini_chain_list(void)
{
    chain_list_t *chain = malloc(sizeof(chain_list_t));

    if (!chain || !(chain->p_begin = ini_player(chain)))
        return (NULL);
    chain->e_nb = 0;
    chain->p_nb = 1;
    chain->p_end = chain->p_begin;
    chain->e_begin = NULL;
    chain->e_end = NULL;
    return (chain);
}
