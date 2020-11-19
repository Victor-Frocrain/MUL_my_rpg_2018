/*
** EPITECH PROJECT, 2019
** fight_action.c
** File description:
** manage action during fight
*/

#include "rpg.h"

bool manage_home_scene_action(int target, game_t *game)
{
    bool is_error = false;

    if (target == 3 && rand() / (RAND_MAX / 10 + 1) > 2 &&
    game->rpg->pnj->is_boss == false) {
        game->rpg->is_fighting = false;
        destroy_enemy(game->rpg->chain_list);
        free(game->rpg->fight->order);
    } else
        is_error = next_turn(game);
    return (is_error);
}

bool manage_attack_scene_action(int target, game_t *game)
{
    enemy_t *enemy = find_enemy_attacked(game, target);
    bool is_error = false;
    player_t *player = find_stat_player(game->rpg->chain_list, \
game->rpg->fight->order[game->rpg->fight->turn].stat);
    int dmg = player->stat.min_dmg;

    if (player->stat.max_dmg - player->stat.min_dmg > 0)
        dmg = rand() / (RAND_MAX / (player->stat.max_dmg - \
player->stat.min_dmg)) + player->stat.min_dmg;
    enemy->stat.life -= dmg;
    if (enemy->stat.life <= 0)
        is_error = !remove_enemy(game, enemy);
    if (!is_error)
        is_error = next_turn(game);
    return (is_error);
}

bool manage_fight_action(char *name, int target, game_t *game)
{
    bool is_error = false;
    fight_scene_t *prev = game->rpg->fight->scene->prev;

    if (!name)
        is_error = manage_home_scene_action(target, game);
    if (name && my_strcmp(name, "Attack")) {
        if (prev && my_strcmp(prev->name, "Spell"))
            is_error = manage_spell(game, target);
        else
            is_error = manage_attack_scene_action(target, game);
    }
    game->rpg->fight->scene->target = 0;
    game->rpg->fight->scene = game->rpg->fight->first_scene;
    game->rpg->fight->first_scene->target = 0;
    return (is_error);
}
