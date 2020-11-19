/*
** EPITECH PROJECT, 2019
** manage_text
** File description:
** manage_text
*/

#include "rpg.h"

void display_dial(game_t *game, sfText *text)
{
    if (game->rpg->pnj->is_interact) {
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[back_text]->sprite, NULL);
        sfRenderWindow_drawText(game->window, text, NULL);
    }
    if (game->rpg->pnj->is_waiting) {
        sfRenderWindow_drawSprite(game->window,
        game->rpg->map->elem[back_text]->sprite, NULL);
        sfRenderWindow_drawText(game->window, game->rpg->pnj->text, NULL);
        sfRenderWindow_drawSprite
        (game->window, game->rpg->map->elem[choice]->sprite, NULL);
    }
}

void change_text_params(game_t *game, int i)
{
    sfFloatRect bounds;
    sfVector2f pos;

    if (i < NB_TEXT)
        sfText_setString(game->rpg->pnj->text, game->rpg->pnj->string[i]);
    bounds = sfText_getGlobalBounds(game->rpg->pnj->text);
    pos.x = WIDTH / 2 - bounds.width / 2;
    pos.y = HEIGHT - 200;
    sfText_setPosition(game->rpg->pnj->text, pos);
}

void switch_text(game_t *game, int *diff)
{
    static int top = 0;

    if (game->rpg->pnj->is_waiting)
        manage_choice(game, &top);
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
    game->rpg->pnj->is_pressed == false) {
        game->rpg->pnj->is_pressed = true;
        if (game->rpg->pnj->is_waiting)
            check_decision(game, top, diff);
        game->rpg->pnj->progress++;
        if (game->rpg->pnj->progress >= NB_TEXT ||
        game->rpg->pnj->string[game->rpg->pnj->progress] == NULL) {
            game->rpg->pnj->is_interact = false;
            game->rpg->pnj->progress--;
            return;
        }
        change_text_params(game, game->rpg->pnj->progress);
    }
}

void display_talk(game_t *game, int *diff)
{
    if (game->rpg->pnj->is_interact)
        switch_text(game, diff);
}
