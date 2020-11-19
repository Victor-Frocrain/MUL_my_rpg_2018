/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** spell_effect.c
*/

#include "rpg.h"

void remove_effect(stat_t *stat, effect_t *to_removed)
{
    effect_t *eff = stat->effect;

    if (stat->effect == to_removed) {
        if (stat->effect->next)
            stat->effect = stat->effect->next;
        else
            stat->effect = NULL;
    } else {
        for (; eff && eff->next != to_removed; eff = eff->next);
        if (to_removed->next)
            eff->next = to_removed->next;
        else
            eff->next = NULL;
    }
    free(to_removed);
}

void send_effect(effect_t *effect, stat_t *stat)
{
    effect_t *eff = stat->effect;

    if (eff) {
        for (; eff && eff->next; eff = eff->next);
        eff->next = effect;
    } else
        stat->effect = effect;
    manage_effect(stat, effect);
}

void manage_effect(stat_t *stat, effect_t *effect)
{
    for (effect_t *eff = effect; eff; eff = eff->next) {
        if (my_strcmp(eff->name, "Heal"))
            stat->life = (stat->life + eff->force > stat->max_life)?\
stat->max_life:stat->life + eff->force;
        else
            stat->life = (stat->life - eff->force < 0)?0:\
stat->life - eff->force;
        eff->nb_turn--;
        if (eff->nb_turn < 1)
            remove_effect(stat, eff);
    }
}
