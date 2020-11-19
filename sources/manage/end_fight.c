/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** manage_end_fight.c
*/

#include "rpg.h"

bool is_game_over(game_t *game)
{
    return (game->rpg->chain_list->p_nb <= 0);
}

bool is_fight_winned(game_t *game)
{
    if (game->rpg->pnj->is_daemon && game->rpg->chain_list->e_nb <= 0) {
        game->rpg->pnj->dragon_unlocked = true;
        game->rpg->pnj->is_daemon = false;
    }
    if (game->rpg->pnj->is_final && game->rpg->chain_list->e_nb <= 0)
        game->rpg->win = true;
    return (game->rpg->chain_list->e_nb <= 0);
}

bool is_end(game_t *game)
{
    return (!((game->rpg->is_game_over = is_game_over(game)) \
|| is_fight_winned(game)));
}

void gave_rewards_to_players(game_t *game)
{
    chain_list_t *chain_list = game->rpg->chain_list;
    int count = 0;

    for (enemy_t *enemy = chain_list->e_begin; enemy; enemy = enemy->next) {
        count += enemy->stat.gold;
        for (player_t *player = chain_list->p_begin; player; \
            player = player->next)
            player->stat.xp += enemy->stat.xp;
    }
    for (player_t *player = chain_list->p_begin; player; \
    player = player->next) {
        manage_lvl_up(player);
        player->stat.gold += (count / 2) / game->rpg->chain_list->p_nb;
    }
    game->rpg->money += count / 2;
}
