/*
** EPITECH PROJECT, 2019
** load_player_stat
** File description:
** load_player_stat
*/

#include "rpg.h"

void load_player_stat(player_t *player, char *str)
{
    player->stat.effect = NULL;
    player->level = my_get_int_in_str(str, 1);
    player->stat.name = my_get_str_in_str(str, 2);
    player->stat.is_dead = my_get_int_in_str(str, 3);
    player->stat.gold = my_get_int_in_str(str, 4);
    player->stat.xp = my_get_int_in_str(str, 5);
    player->stat.max_life = my_get_int_in_str(str, 6);
    player->stat.life = my_get_int_in_str(str, 6);
    player->stat.max_mana = my_get_int_in_str(str, 7);
    player->stat.mana = my_get_int_in_str(str, 7);
    player->stat.magic_power = my_get_int_in_str(str, 8);
    player->stat.min_dmg = my_get_int_in_str(str, 9);
    player->stat.max_dmg = my_get_int_in_str(str, 10);
    player->stat.image = ini_img(my_get_str_in_str(str, 11), \
v_pos(2, 2), ini_rect(100, 0, 30, 50), v_pos(270, 50));
}
