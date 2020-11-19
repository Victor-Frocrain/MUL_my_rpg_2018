/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** level
*/

#include "rpg.h"

player_t *find_player_targetted(chain_list_t *chain_list, int target)
{
    player_t *player = chain_list->p_begin;

    for (int i = 0; player && i < target; i++) {
        while (player && player->stat.is_dead)
            player = player->next;
        if (player)
            player = player->next;
    }
    return (player);
}

bool display_level(game_t *game, player_t *player, sfVector2f pos)
{
    char *lvl = my_getstr(player->level);
    char *str;

    if (!lvl)
        return (false);
    str = my_strcat("Level : ", lvl);
    if (!str)
        return (false);
    sfText_setCharacterSize(game->rpg->fight->text.text, 18);
    sfText_setString(game->rpg->fight->text.text, str);
    sfText_setPosition(game->rpg->fight->text.text, pos);
    sfRenderWindow_drawText(game->window, game->rpg->fight->text.text, NULL);
    free(str);
    free(lvl);
    sfText_setCharacterSize(game->rpg->fight->text.text, 15);
    return (true);
}
