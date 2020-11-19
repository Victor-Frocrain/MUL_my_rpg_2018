/*
** EPITECH PROJECT, 2019
** text_save
** File description:
** text_save function
*/

#include "rpg.h"

void print_text_menu(game_t *game, char *str, sfVector2f pos, int size)
{
    sfText_setCharacterSize(game->menu.text, size);
    sfText_setPosition(game->menu.text, pos);
    sfText_setString(game->menu.text, str);
    sfRenderWindow_drawText(game->window, game->menu.text, NULL);
}

char *get_good_save(int i, char *str, int nb)
{
    if (i == 0)
        str = my_get_str_fd("save1", nb);
    if (i == 1)
        str = my_get_str_fd("save2", nb);
    if (i == 2)
        str = my_get_str_fd("save3", nb);
    return (str);
}

void text_save_next(game_t *game, char *level, char *gold, int i)
{
    print_text_menu(game, "Level :", v_pos(1400, 180 + i * 250), 40);
    if (level)
        print_text_menu(game, level, v_pos(1550, 180 + i * 250), 40);
    else
        print_text_menu(game, "N/A", v_pos(1550, 180 + i * 250), 40);
    print_text_menu(game, "Gold :", v_pos(1400, 240 + i * 250), 40);
    if (gold)
        print_text_menu(game, gold, v_pos(1550, 240 + i * 250), 40);
    else
        print_text_menu(game, "N/A", v_pos(1550, 240 + i * 250), 40);
}

void text_save(game_t *game)
{
    char *nb;
    char *level;
    char *gold;

    for (int i = 0; i < 3; i++) {
        nb = my_getstr(i + 1);
        level = get_good_save(i, level, 1);
        gold = get_good_save(i, gold, 4);
        print_text_menu(game, "Save :", v_pos(980, 160 + i * 250), 60);
        print_text_menu(game, nb, v_pos(1180, 160 + i * 250), 60);
        text_save_next(game, level, gold, i);
        free(nb);
    }
}
