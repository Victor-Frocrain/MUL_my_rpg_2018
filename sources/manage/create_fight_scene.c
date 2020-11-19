/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create_fight_scene.c
*/

#include "rpg.h"

int count_spell(spell_t *spells)
{
    int count = 0;

    for (spell_t *spell = spells; spell; count++)
        spell = spell->next;
    return (count);
}

bool prepare_next_scene(rpg_t *rpg, spell_t *spell, int count,
fight_scene_t *fight_scene)
{
    spell_t *spells = spell;
    int j;

    for (int i = 0; i < count; i++) {
        if (!(fight_scene->next[i] = malloc(sizeof(fight_scene_t))))
            return (NULL);
        j = (spells->is_attack) ? rpg->chain_list->e_nb : rpg->chain_list->p_nb;
        fight_scene->next[i]->av = (spells->is_attack) ? \
rpg->fight->enemy_scene->av : rpg->fight->player_scene->av;
        fight_scene->next[i]->next = (spells->is_attack) ? \
rpg->fight->enemy_scene->next : rpg->fight->player_scene->next;
        fight_scene->next[i]->target = 0;
        fight_scene->next[i]->name = "Attack";
        fight_scene->next[i]->prev = fight_scene;
        for (int x = 0; x < j; x++)
            fight_scene->next[i]->next[x] = NULL;
        spells = spells->next;
    }
    fight_scene->next[count] = NULL;
    return (true);
}

bool init_spell_scene(rpg_t *rpg, char **av, int count, spell_t *spell)
{
    fight_scene_t *fight_scene = malloc(sizeof(fight_scene_t));

    if (!fight_scene)
        return (false);
    fight_scene->next = malloc(sizeof(fight_scene_t *) * (count + 1));
    if (!fight_scene->next)
        return (false);
    fight_scene->prev = rpg->fight->scene;
    fight_scene->name = "Spell";
    fight_scene->target = 0;
    fight_scene->av = av;
    if (!prepare_next_scene(rpg, spell, count, fight_scene))
        return (false);
    rpg->fight->scene->next[1] = fight_scene;
    return (true);
}

bool modify_spell_scene(rpg_t *rpg, char **scene, int count, spell_t *spell)
{
    for (int i = 0; rpg->fight->scene->next[1]->next[i]; i++)
        free(rpg->fight->scene->next[1]->next[i]);
    free(rpg->fight->scene->next[1]->next);
    return (init_spell_scene(rpg, scene, count, spell));
}

bool create_spell_scene(game_t *game, stat_t *stat)
{
    player_t *player = find_stat_player(game->rpg->chain_list, stat);
    int count = count_spell(player->spell);
    char **scene;
    int i = 0;

    if (!(scene = malloc(sizeof(char *) * (count + 1))))
        return (false);
    for (spell_t *spell = player->spell; spell && i < count; scene[i] = NULL) {
        scene[i++] = spell->name;
        spell = spell->next;
    }
    if (game->rpg->fight->scene->next[1])
        return (!modify_spell_scene(game->rpg, scene, count, player->spell));
    return (!init_spell_scene(game->rpg, scene, count, player->spell));
}
