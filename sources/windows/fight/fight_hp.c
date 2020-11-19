/*
** EPITECH PROJECT, 2019
** fight_hp.c
** File description:
** display enemy and ally hp
*/

#include "../../../include/rpg.h"

void display_empty_bar(game_t *game, sfVector2f pos, img_t *background, \
sfVector2f scale)
{
    sfSprite_setScale(background[4].sprite, scale);
    sfSprite_setPosition(background[4].sprite, pos);
    sfRenderWindow_drawSprite(game->window, background[4].sprite, NULL);
}

void display_scaled_bar(game_t *game, sfVector2f pos, img_t background,
float scale)
{
    sfVector2f v_scale = {scale * 1.9, 1.5};
    sfVector2f empty_pos = {pos.x - 5, pos.y - 2};

    display_empty_bar(game, empty_pos, game->rpg->fight->background, \
v_pos(2, 2));
    sfSprite_setScale(background.sprite, v_scale);
    sfSprite_setPosition(background.sprite, pos);
    sfRenderWindow_drawSprite(game->window, background.sprite, NULL);
}

bool display_text_rate(stat_t stat, game_t *game, sfVector2f pos)
{
    char *str = my_getstr(stat.life);
    char *str2;
    char *str3;
    float new_pos;

    if (!str)
        return (false);
    if (!(str2 = my_strcat(str, " / ")))
        return (false);
    free(str);
    if (!(str = my_getstr(stat.max_life)) || !(str3 = my_strcat(str2, str)))
        return (false);
    new_pos = my_strlen(str3);
    pos.x -= (new_pos / 2) * 8;
    sfText_setPosition(game->rpg->fight->text.text, pos);
    sfText_setString(game->rpg->fight->text.text, str3);
    sfRenderWindow_drawText(game->window, game->rpg->fight->text.text, NULL);
    (free(str3), free(str2), free(str));
    return (true);
}

void display_enemy_hp(game_t *game)
{
    enemy_t *enemy = game->rpg->chain_list->e_begin;
    float scale;
    float hp;

    for (int pos = 0; enemy; enemy = enemy->next, pos++) {
        hp = enemy->stat.life;
        scale = hp / enemy->stat.max_life;
        display_scaled_bar(game, v_pos(105, HEIGHT - 228 + 30 * pos), \
game->rpg->fight->background[2], scale);
        display_text_rate(enemy->stat, game, \
v_pos(105 + (game->rpg->fight->background[2].rect.width * 1.8) / 2, \
HEIGHT - 231 + 30 * pos));
        display_text(enemy->stat.name, game, v_pos(110 + \
(game->rpg->fight->background[4].rect.width * 2), HEIGHT - 231 + 30 * pos));
    }
    sfText_setCharacterSize(game->rpg->fight->text.text, 40);
}

void display_fighter(game_t *game)
{
    player_t *player = game->rpg->chain_list->p_begin;
    float hp;
    float scale;

    sfText_setCharacterSize(game->rpg->fight->text.text, 16);
    for (int pos = 0; player; player = player->next, pos++) {
        hp = player->stat.life;
        scale = hp / player->stat.max_life;
        display_mana(player->stat, game, v_pos(3 * WIDTH / 4 + 100, \
HEIGHT - 210 + 50 * pos));
        display_xp_during_fight(player, game, v_pos(3 * WIDTH / 4 + 100, \
HEIGHT - 190 + 50 * pos));
        display_scaled_bar(game, v_pos(3 * WIDTH / 4 + 105, HEIGHT - 228 + \
30 * pos), game->rpg->fight->background[2], scale);
        display_text_rate(player->stat, game, \
v_pos(3 * WIDTH / 4 + 105 + (game->rpg->fight->background[2].rect.width * \
1.8) / 2, HEIGHT - 231 + 50 * pos));
        display_text(player->stat.name, game, v_pos(3 * WIDTH / 4 + 105 - \
my_strlen(player->stat.name) * 8, HEIGHT - 231 + 30 * pos));
    }
    display_enemy_hp(game);
}
