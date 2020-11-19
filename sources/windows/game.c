/*
** EPITECH PROJECT, 2019
** window_game.c
** File description:
** window_game.c
*/

#include "../../include/rpg.h"

void game_window(game_t *game)
{
    sfVector2f init_pos = game->rpg->map->begin->pos;

    if (game->rpg->is_fighting) {
        display_fight(game);
        manage_end_fight(game);
    } else if (game->rpg->win == false) {
        if (manage_move(game) == false || \
(init_pos.x == game->rpg->map->begin->pos.x && \
init_pos.y == game->rpg->map->begin->pos.y))
            game->rpg->player->image->rect.left = 0;
        sfSprite_setTextureRect(game->rpg->player->image->sprite, \
game->rpg->player->image->rect);
        display_map(game, game->rpg->map->begin->map);
    }
    if (game->rpg->win)
        display_win(game);
    display_pause(game);
    display_inventory(game);
}
