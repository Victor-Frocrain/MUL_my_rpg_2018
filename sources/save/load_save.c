/*
** EPITECH PROJECT, 2019
** load_save
** File description:
** load_save function
*/

#include "rpg.h"

chain_list_t *load_chain_list(int nb_player)
{
    chain_list_t *chain = malloc(sizeof(chain_list_t));

    if (!chain)
        return (NULL);
    chain->e_nb = 0;
    chain->p_nb = nb_player;
    chain->e_begin = NULL;
    chain->e_end = NULL;
    chain->p_begin = NULL;
    chain->p_end = NULL;
    return (chain);
}

void load_save(game_t *game, char *filepath)
{
    int nb_player = 0;
    int fd;
    char *str = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return;
    while (get_next_line(fd))
        nb_player++;
    close(fd);
    game->rpg->chain_list->p_nb = nb_player;
    game->rpg->chain_list = load_chain_list(nb_player);
    fd = open(filepath, O_RDONLY);
    for (int i = 0; i < nb_player; i++) {
        str = get_next_line(fd);
        if (i == 0)
            load_first_player(game, str);
        else
            load_player(game, str);
    }
}
