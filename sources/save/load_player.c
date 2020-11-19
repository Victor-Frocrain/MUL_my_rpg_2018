/*
** EPITECH PROJECT, 2019
** load_save
** File description:
** load_save function
*/

#include "rpg.h"

player_t *load_player(game_t *game, char *str)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->next = NULL;
    player->prev = game->rpg->chain_list->p_end;
    game->rpg->chain_list->p_end = player;
    load_player_stat(player, str);
    player->spell = load_player_spell(str);
    return (player);
}

player_t *load_first_player(game_t *game, char *str)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->next = NULL;
    player->prev = NULL;
    game->rpg->chain_list->p_begin = player;
    game->rpg->chain_list->p_end = player;
    load_player_stat(player, str);
    if (check_nb_info(str, 14))
        player->spell = load_player_spell(str);
    else
        player->spell = NULL;
    return (player);
}
