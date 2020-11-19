/*
** EPITECH PROJECT, 2019
** create_enemy.c
** File description:
** creating enemy
*/

#include "rpg.h"

bool is_enemy_line_correct(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        (str[i] == ':')?(str[i] = 0, count++):0;
    if (count != 8) {
        my_puterror("Error: Enemy stat wrong format\n");
        return (false);
    }
    return (true);
}

void link_enemy_to_chain_list(game_t *game, enemy_t *enemy)
{
    enemy->next = NULL;
    enemy->prev = NULL;
    if (!game->rpg->chain_list->e_begin) {
        game->rpg->chain_list->e_begin = enemy;
        game->rpg->chain_list->e_end = enemy;
    } else {
        game->rpg->chain_list->e_end->next = enemy;
        enemy->prev = game->rpg->chain_list->e_end;
        game->rpg->chain_list->e_end = enemy;
    }
}

bool create_enemy(game_t *game)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    game->rpg->chain_list->e_nb++;
    if (!enemy || !fill_stat(&enemy->stat, \
rand() % (game->rpg->nb_enemy - 2), game))
        return (false);
    link_enemy_to_chain_list(game, enemy);
    return (true);
}
