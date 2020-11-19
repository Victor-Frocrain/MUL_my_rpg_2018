/*
** EPITECH PROJECT, 2019
** fight.c
** File description:
** fight.c
*/

#include "rpg.h"

void manage_hud_move(game_t *game, int key)
{
    int max = count_arg(game->rpg->fight->scene->av);
    int *target = &game->rpg->fight->scene->target;

    if (key == sfKeyUp || key == sfKeyDown)
        (key == sfKeyUp) ? (*target)--: (*target)++;
    ((*target) >= max) ? ((*target) = 0):0;
    ((*target) < 0) ? ((*target) = max - 1):0;
    if (key == sfKeyRight && game->rpg->fight->scene->next) {
        if (!game->rpg->fight->scene->next[game->rpg->fight->scene->target]) {
            manage_fight_action(game->rpg->fight->scene->name, \
game->rpg->fight->scene->target, game);
        } else
            game->rpg->fight->scene = \
game->rpg->fight->scene->next[game->rpg->fight->scene->target];
    }
    if (key == sfKeyLeft && game->rpg->fight->scene->prev) {
        game->rpg->fight->scene->target = 0;
        game->rpg->fight->scene = game->rpg->fight->scene->prev;
    }
}

void display_background(game_t *game)
{
    sfSprite_setPosition(game->rpg->fight->background[6].sprite, \
    v_pos(0, -300));
    sfRenderWindow_drawSprite(game->window, \
game->rpg->fight->background[6].sprite, NULL);
    sfSprite_setPosition(game->rpg->fight->background[7].sprite, v_pos(0, 387));
    sfRenderWindow_drawSprite(game->window, \
game->rpg->fight->background[7].sprite, NULL);
}

void display_fight(game_t *game)
{
    display_background(game);
    display_fight_sprite(game->rpg->chain_list, game);
    sfSprite_setPosition(game->rpg->fight->background[1].sprite, \
v_pos(WIDTH / 2 - 280 , HEIGHT - 230 + game->rpg->fight->scene->target * 50));
    for (int i = 0; i < 2; i++)
        display_next_anim(&game->rpg->fight->background[i], game, 100);
    display_fighter(game);
    display_fight_text(game, game->rpg->fight->scene->av);
    manage_turn(game);
    if (!game->rpg->chain_list->e_begin) {
        game->rpg->is_fighting = false;
        destroy_fight(game->rpg->fight);
        game->rpg->fight = NULL;
        game->rpg->last_fight = \
sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock));
    }
}
