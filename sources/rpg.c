/*
** EPITECH PROJECT, 2019
** rpg.c
** File description:
** rpg.c
*/

#include "manage_scene.h"

void manage_event(game_t *game)
{
    if (game->event.type == sfEvtClosed || \
game->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(game->window);
    }
}

int rpg(void)
{
    game_t *game = ini_game();

    srand(sfTime_asMicroseconds(sfClock_getElapsedTime(game->clock)));
    if (!game)
        return (MY_ERROR);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    if (SOUND)
        sfMusic_play(game->sound[0]);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        scene[game->scene].func(game);
        sfRenderWindow_display(game->window);
        if (sfRenderWindow_pollEvent(game->window, &game->event))
            manage_event(game);
    }
    destroy_game(game);
    free(game);
    return (MY_SUCCESS);
}
