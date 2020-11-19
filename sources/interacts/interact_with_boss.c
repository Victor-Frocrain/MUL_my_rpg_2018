/*
** EPITECH PROJECT, 2019
** interact_with_boss
** File description:
** interact_with_boss
*/

#include "rpg.h"

void disapear_boss(game_t *game)
{
    int i = game->rpg->pnj->pos_y;
    int j = game->rpg->pnj->pos_x;

    if (game->rpg->map->begin->map[i] && game->rpg->map->begin->map[i][j] &&
        (game->rpg->map->begin->map[i][j] == 'D' ||
        game->rpg->map->begin->map[i][j] == 'd'))
        game->rpg->map->begin->map[i][j] = ' ';
}

void interact_with_boss(game_t *game, int progress, int i, int j)
{
    if (game->rpg->pnj->is_interact == false &&
    game->rpg->pnj->progress < progress) {
        game->rpg->pnj->is_interact = true;
        game->rpg->pnj->is_boss = true;
        game->rpg->pnj->progress = progress;
        change_text_params(game, game->rpg->pnj->progress);
        display_talk(game, 0);
        game->rpg->pnj->pos_x = j;
        game->rpg->pnj->pos_y = i;
    }
}
