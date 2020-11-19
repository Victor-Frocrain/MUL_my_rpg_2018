/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display_fight_sprite.c
*/

#include "rpg.h"

sfVector2f calc_pos(int pos, int nb, bool is_ally)
{
    sfVector2f res = {(is_ally)?WIDTH - 100:100 , 0};

    if (nb == 1)
        res.y = HEIGHT / 2 - 80;
    if (nb == 2)
        res.y = HEIGHT / 2 - 140 + 100 * pos;
    if (nb == 3) {
        res.y = HEIGHT / 2 - 200 + 150 * pos;
        if (pos == 0 || pos == 2)
            res.x = (is_ally) ? res.x + 100 : res.x - 100;
    }
    if (nb == 4) {
        res.y = HEIGHT / 2 - 450 + 300 * pos;
        res.x = (pos == 0 || pos == 3) ? res.x + 100 : res.x;
    }
    return (res);
}

void display_fight_sprite(chain_list_t *chain_list, game_t *game)
{
    player_t *player = chain_list->p_begin;
    enemy_t *enemy = chain_list->e_begin;

    for (int i = 0; player; i++) {
        if (!player->stat.is_dead) {
            sfSprite_setPosition(player->stat.image.sprite, \
calc_pos(i, chain_list->p_nb, true));
            display_next_anim(&player->stat.image, game, 200);
        }
        player = player->next;
    }
    for (int i = 0; enemy; i++) {
        if (!enemy->stat.is_dead) {
            sfSprite_setPosition(enemy->stat.image.sprite, \
calc_pos(i, chain_list->e_nb, false));
            display_next_anim(&enemy->stat.image, game, 200);
        }
        enemy = enemy->next;
    }
}
