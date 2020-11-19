/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** mana.c
*/

#include "rpg.h"

enemy_t *find_enemy_attacked(game_t *game, int target)
{
    enemy_t *enemy = game->rpg->chain_list->e_begin;

    for (int i = 0; enemy && i < target; i++) {
        while (enemy && enemy->stat.is_dead)
            enemy = enemy->next;
        if (enemy)
            enemy = enemy->next;
    }
    return (enemy);
}

player_t *find_stat_player(chain_list_t *chain_list, stat_t *stat)
{
    player_t *player = chain_list->p_begin;

    while (player && !is_same_stat(player->stat, *stat))
        player = player->next;
    return (player);
}

bool copy_spell_toeffect(game_t *game, stat_t *stat, player_t *player, \
spell_t *spell)
{
    effect_t *effect;

    if (player->stat.mana >= spell->cost) {
        if (!(effect = malloc(sizeof(effect_t))))
            return (true);
        effect->force = player->stat.magic_power;
        effect->name = spell->name;
        effect->nb_turn = spell->nb;
        send_effect(effect, stat);
    }
    return (next_turn(game));
}

bool manage_spell(game_t *game, int target)
{
    stat_t *stat;
    player_t *player = find_stat_player(game->rpg->chain_list, \
game->rpg->fight->order[game->rpg->fight->turn].stat);
    spell_t *spell = player->spell;
    enemy_t *en;
    player_t *pl;

    for (int i = 0; i < game->rpg->fight->scene->prev->target; i++)
        spell = spell->next;
    if (spell->is_attack)
        en = find_enemy_attacked(game, target);
    else
        pl = find_player_targetted(game->rpg->chain_list, target);
    stat = (spell->is_attack) ? &en->stat : &pl->stat;
    return (copy_spell_toeffect(game, stat, player, spell));
}

void display_mana(stat_t stat, game_t *game, sfVector2f pos)
{
    float mana = stat.mana;
    sfVector2f poss = {pos.x + 4, pos.y};
    sfVector2f scale = {(mana / stat.max_mana) * 1.92, 1.7};
    stat_t stats;
    int mid = game->rpg->fight->background[4].rect.width / 2;
    int text_pos = 4 + game->rpg->fight->background[3].rect.width - \
(3 + my_int_len(stat.mana) + my_int_len(stat.max_mana)) * 8 + mid;

    stats.max_life = stat.max_mana;
    stats.life = stat.mana;
    display_empty_bar(game, pos, game->rpg->fight->background, v_pos(2, 2));
    sfSprite_setPosition(game->rpg->fight->background[3].sprite, poss);
    sfSprite_setScale(game->rpg->fight->background[3].sprite, scale);
    sfRenderWindow_drawSprite(game->window, \
game->rpg->fight->background[3].sprite, NULL);
    display_text_rate(stats, game, v_pos(pos.x + text_pos, pos.y - 1));
}
