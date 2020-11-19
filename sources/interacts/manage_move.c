/*
** EPITECH PROJECT, 2019
** manage_move
** File description:
** manage_move
*/

#include "rpg.h"

void rotate_player(game_t *game, int key)
{
    if (key == sfKeyQ)
        game->rpg->player->image->rect.top = 200 / 4;
    if (key == sfKeyD)
        game->rpg->player->image->rect.top = 200 - 200 / 4;
    if (key == sfKeyZ)
        game->rpg->player->image->rect.top = 0;
    if (key == sfKeyS)
        game->rpg->player->image->rect.top = 200 / 2;
    if (game->rpg->pnj->is_interact == false && game->rpg->pnj->progress == 4) {
        game->rpg->pnj->progress = 6;
        change_text_params(game, game->rpg->pnj->progress);
        engage_boss(game, 4);
    }
    if (game->rpg->pnj->is_interact == false &&
    game->rpg->pnj->progress == 10) {
        change_text_params(game, game->rpg->pnj->progress);
        game->rpg->pnj->progress = 11;
        engage_boss(game, 5);
    }
}

bool detect_if_hor_ver(bool move)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyS)) &&
        (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyD)))
        move = true;
    if ((sfKeyboard_isKeyPressed(sfKeyUp) ||
        sfKeyboard_isKeyPressed(sfKeyDown)) &&
        (sfKeyboard_isKeyPressed(sfKeyLeft) ||
        sfKeyboard_isKeyPressed(sfKeyRight)))
        move = true;
    return (move);
}

bool manage_vertical(game_t *game, bool move)
{
    int key = 0;

    if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ))
        key = sfKeyZ;
    if (sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
        key = sfKeyS;
    rotate_player(game, key);
    if (!game->pause && key == sfKeyZ && manage_collisions(game, key)) {
        turn_player(game, key);
        move = true;
    }
    if (!game->pause && key == sfKeyS && manage_collisions(game, key)) {
        turn_player(game, key);
        move = true;
    }
    return (move);
}

bool manage_move(game_t *game)
{
    bool move = false;
    int key = 0;

    if (game->rpg->pnj->is_interact)
        return (false);
    if (sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyQ))
        key = sfKeyQ;
    if (sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD))
        key = sfKeyD;
    rotate_player(game, key);
    if (!game->pause && key == sfKeyQ && manage_collisions(game, key)) {
        turn_player(game, key);
        move = true;
    }
    if (!game->pause && key == sfKeyD && manage_collisions(game, key)) {
        turn_player(game, key);
        move = true;
    }
    move = manage_vertical(game, move);
    manage_interacts(game);
    return (detect_if_hor_ver(move));
}
