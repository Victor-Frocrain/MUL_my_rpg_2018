/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manage_xp.c
*/

#include "rpg.h"

int get_xp_lvl_up(player_t *player)
{
    int xp = 0;

    for (int i = 1; i <= player->level; i++)
        xp += 2;
    return (xp + 8 * player->level);
}

void level_up(stat_t *stat, int lvl)
{
    int bonus_hp = lvl * 0.5 + 4;
    int bonus_dmg = lvl * 0.25 + 2;
    int bonus_magic = lvl * 0.25 + 1;

    (*stat).max_life += bonus_hp;
    (*stat).life += bonus_hp;
    (*stat).max_dmg += bonus_dmg + lvl * 0.25;
    (*stat).min_dmg += bonus_dmg;
    (*stat).magic_power += bonus_magic;
}

void manage_lvl_up(player_t *player)
{
    int xp_needed = get_xp_lvl_up(player);

    if (player->stat.xp >= xp_needed) {
        level_up(&player->stat, player->level);
        player->level++;
        player->stat.xp -= xp_needed;
    }
}

int my_int_len(int nb)
{
    int count = 0;

    for (int mult = 1; nb / mult > 0; count++, mult *= 10);
    return (count);
}

void display_xp_during_fight(player_t *player, game_t *game, sfVector2f pos)
{
    float xp = player->stat.xp;
    float max_xp = get_xp_lvl_up(player);
    sfVector2f scale = {xp / max_xp, 0.7};
    stat_t stat;
    int mid = game->rpg->fight->background[4].rect.width / 2;
    int text_pos = 4 + game->rpg->fight->background[5].rect.width - \
(3 + my_int_len(xp) + my_int_len(max_xp)) + mid;

    display_level(game, player, v_pos(pos.x - 10, pos.y));
    stat.max_life = max_xp;
    stat.life = xp;
    display_empty_bar(game, v_pos(pos.x + mid, pos.y), \
game->rpg->fight->background, v_pos(1, 1));
    sfSprite_setScale(game->rpg->fight->background[5].sprite, scale);
    sfSprite_setPosition(game->rpg->fight->background[5].sprite, \
v_pos(pos.x + 4 + mid, pos.y + 1));
    sfRenderWindow_drawSprite(game->window, \
game->rpg->fight->background[5].sprite, NULL);
    display_text_rate(stat, game, v_pos(pos.x + text_pos, pos.y + 4));
}
