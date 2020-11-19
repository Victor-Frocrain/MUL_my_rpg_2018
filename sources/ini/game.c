/*
** EPITECH PROJECT, 2019
** ini_game.c
** File description:
** ini game sructure
*/

#include "../../include/rpg.h"

game_t *init_game_elem(game_t *game)
{
    for (int i = 0; i < NB_PIXEL; i++)
        if ((game->pixel[i] = init_particles()) == NULL)
            return (NULL);
    for (int i = 0; i < NB_SPARK; i++)
        if ((game->spark[i] = init_sparks()) == NULL)
            return (NULL);
    game->font = sfFont_createFromFile("sprite/Navilla.ttf");
    if ((game->rpg->pnj = init_pnj()) == NULL)
        return (NULL);
    init_text(game);
    return (game);
}

game_t *ini_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {WIDTH, HEIGHT, BITS};

    if (!game || !(game->is_key_pressed = malloc(sizeof(bool) * 4)))
        return (NULL);
    for (int i = 0; i < 4; i++)
        game->is_key_pressed[i] = false;
    game->clock = sfClock_create();
    game->window = sfRenderWindow_create(mode, "Dragon Fantasy",
    sfResize | sfClose, NULL);
    game->pause = false;
    game->already_done = 0;
    game->scene = 0;
    game->sound = ini_music();
    game->menu = ini_menu();
    game->rpg = ini_rpg();
    game->rpg->inv = ini_inv();
    if ((game = init_maps(game)) == NULL)
        return (NULL);
    return (init_game_elem(game));
}
