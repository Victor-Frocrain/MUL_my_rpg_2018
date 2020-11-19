/*
** EPITECH PROJECT, 2019
** load_player_spell
** File description:
** load_player_spell
*/

#include "rpg.h"

spell_t *fill_player_spell(char *str, spell_t *spell)
{
    for (int i = 15; check_nb_info(str, i); i += 4) {
        spell->next = malloc(sizeof(spell_t));
        if (!spell->next)
            return (NULL);
        spell->name = my_get_str_in_str(str, 11);
        spell->nb = my_get_int_in_str(str, 12);
        spell->cost = my_get_int_in_str(str, 13);
        if (my_get_int_in_str(str, 14) == 0)
            spell->is_attack = false;
        else
            spell->is_attack = true;
    }
    return (spell);
}

spell_t *load_player_spell(char *str)
{
    spell_t *spell = malloc(sizeof(spell_t));

    if (!spell)
        return (NULL);
    spell->name = my_get_str_in_str(str, 11);
    spell->nb = my_get_int_in_str(str, 12);
    spell->cost = my_get_int_in_str(str, 13);
    if (my_get_int_in_str(str, 14) == 0)
        spell->is_attack = false;
    else
        spell->is_attack = true;
    return (fill_player_spell(str, spell));
}
