/*
** EPITECH PROJECT, 2019
** go_fight
** File description:
** go_fight
*/

#include "../../include/rpg.h"

bool create_boss(game_t *game, int enemy_id)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    game->rpg->chain_list->e_nb++;
    if (!enemy || !fill_stat(&enemy->stat, \
enemy_id, game))
        return (false);
    link_enemy_to_chain_list(game, enemy);
    return (true);
}

bool engage_boss(game_t *game, int enemy_id)
{
    if (!game->rpg->fight)
        if (!(game->rpg->fight = ini_fight()))
            return (true);
    game->rpg->fight->turn = 0;
    create_boss(game, enemy_id);
    if (!creating_enemy_scene(game, 1))
        return (true);
    if (!(game->rpg->fight->order = ini_order(game->rpg->chain_list)))
        return (true);
    game->rpg->is_fighting = true;
    if (!game->rpg->fight->player_scene)
        if (ini_player_fight_scene(game->rpg))
            return (true);
    if (game->rpg->fight->order->is_ally)
        create_spell_scene(game, game->rpg->fight->order->stat);
    else
        game->rpg->fight->scene->next[1] = NULL;
    disapear_boss(game);
    return (false);
}

void check_if_final(game_t *game, char c, int i, int j)
{
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock));
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = \
sfSprite_getGlobalBounds(game->rpg->player->image->sprite);

    if (c == 'd' && player.x + bounds.width > map.x + 50 * j && \
player.x < map.x + 50 * j + 50 && player.y + bounds.height > map.y + 50 * i && \
player.y < map.y + 50 * i + 50 && !game->rpg->is_fighting && \
game->rpg->last_fight + 1000 <= time && game->rpg->pnj->dragon_unlocked) {
        if (SOUND) {
            sfMusic_stop(game->sound[2]);
            sfMusic_play(game->sound[1]);
        }
        game->rpg->pnj->is_final = true;
        interact_with_boss(game, 10, i, j);
    }
}

void check_if_engage(game_t *game, char c, int i, int j)
{
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock));
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = \
sfSprite_getGlobalBounds(game->rpg->player->image->sprite);

    if (c == 'D' && player.x + bounds.width > map.x + 50 * j && \
player.x < map.x + 50 * j + 50 && player.y + bounds.height > map.y + 50 * i && \
player.y < map.y + 50 * i + 50 && !game->rpg->is_fighting && \
game->rpg->last_fight + 1000 <= time) {
        if (SOUND) {
            sfMusic_stop(game->sound[2]);
            sfMusic_play(game->sound[1]);
        }
        game->rpg->pnj->is_daemon = true;
        interact_with_boss(game, 3, i, j);
    }
}

void go_fight(game_t *game, char c, int i, int j)
{
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock));
    int random = rand() % 500;
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f map = game->rpg->map->begin->pos;
    sfFloatRect bounds = \
sfSprite_getGlobalBounds(game->rpg->player->image->sprite);

    if ((c == 'G' || c == 'f') && player.x + bounds.width > map.x + 50 * j && \
player.x < map.x + 50 * j + 50 && player.y + bounds.height > map.y + 50 * i && \
player.y < map.y + 50 * i + 50 && !game->rpg->is_fighting && \
game->rpg->last_fight + 1000 <= time && random == 0) {
        if (SOUND) {
            sfMusic_stop(game->sound[2]);
            sfMusic_play(game->sound[1]);
        }
        engage_fight(game);
    }
    check_if_engage(game, c, i, j);
    check_if_final(game, c, i, j);
}
