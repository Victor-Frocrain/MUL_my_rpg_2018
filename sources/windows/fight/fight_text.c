/*
** EPITECH PROJECT, 2019
** display_fight_text.c
** File description:
** displaying text during fight
*/

#include "../../../include/rpg.h"

void display_text(char *str, game_t *game, sfVector2f pos)
{
    sfText_setCharacterSize(game->rpg->fight->text.text, 18);
    sfText_setString(game->rpg->fight->text.text, str);
    sfText_setPosition(game->rpg->fight->text.text, pos);
    sfRenderWindow_drawText(game->window, game->rpg->fight->text.text, NULL);
}

void display_fight_text(game_t *game, char **av)
{
    for (int i = 0; av[i]; i++) {
        if (game->rpg->fight->scene->target == i)
            sfText_setColor(game->rpg->fight->text.text, \
set_color(255, 0, 0, 255));
        if ((game->is_key_pressed[0]\
|| game->is_key_pressed[1]) &&\
game->rpg->fight->scene->target == i)
            sfText_setColor(game->rpg->fight->text.text, \
set_color(255, 255, 0, 255));
        sfText_setString(game->rpg->fight->text.text, av[i]);
        sfText_setPosition(game->rpg->fight->text.text, \
v_pos(WIDTH / 2 - 230 , HEIGHT - 240 + i * 50));
        sfRenderWindow_drawText(game->window, game->rpg->fight->text.text, \
NULL);
        sfText_setColor(game->rpg->fight->text.text, \
set_color(255, 255, 255, 255));
    }
}
