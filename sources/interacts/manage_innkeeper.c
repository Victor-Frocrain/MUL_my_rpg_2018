/*
** EPITECH PROJECT, 2019
** manage_innkeeper
** File description:
** manage_innkeeper
*/

#include "rpg.h"

void check_decision(game_t *game, int top, int *diff)
{
    if (top != 0) {
        game->rpg->pnj->is_waiting = false;
        return;
    }
    if ((*diff) > NB_TEXT - 4) {
        sfRenderWindow_close(game->window);
        return;
    }
    if ((*diff) <= NB_TEXT - 3) {
        (*diff) += 2;
        game->rpg->pnj->progress++;
    }
    else
        game->rpg->pnj->is_waiting = false;
}

void manage_choice_rect(game_t *game, int *top)
{
    sfIntRect rect = {0, 0, 140, 60 / 2};

    rect.top = (*top);
    sfSprite_setTextureRect(game->rpg->map->elem[choice]->sprite, rect);
}

int check_choice_state(bool *left, bool *right)
{
    int change = 0;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && (*left) == false) {
        (*left) = true;
        change++;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyLeft) == false)
        (*left) = false;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && (*right) == false) {
        (*right) = true;
        change--;
    }
    else if (sfKeyboard_isKeyPressed(sfKeyRight) == false)
        (*right) = false;
    return (change);
}

void manage_choice(game_t *game, int *top)
{
    static bool left = false;
    static bool right = false;
    int change = 0;

    manage_choice_rect(game, top);
    change = check_choice_state(&left, &right);
    if (change != 0) {
        if ((*top) == 0)
            (*top) = 60 / 2;
        else
            (*top) = 0;
        manage_choice_rect(game, top);
    }
}

int manage_innkeeper(game_t *game)
{
    int diff = (NB_TEXT - 4) - game->rpg->pnj->progress;

    game->rpg->pnj->is_waiting = true;
    game->rpg->pnj->is_interact = true;
    game->rpg->pnj->is_pressed = true;
    game->rpg->pnj->progress = NB_TEXT - 4;
    change_text_params(game, game->rpg->pnj->progress);
    return (diff);
}
