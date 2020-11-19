/*
** EPITECH PROJECT, 2019
** ini_player.c
** File description:
** ini_player.c
*/

#include "rpg.h"

bool ini_player_fight_scene(rpg_t *rpg)
{
    fight_scene_t *player_scene = malloc(sizeof(fight_scene_t));
    char **scene = malloc(sizeof(char *) * (rpg->chain_list->p_nb + 1));
    player_t *player = rpg->chain_list->p_begin;

    player_scene->next = malloc(sizeof(fight_scene_t *) * \
(rpg->chain_list->p_nb));
    if (!player_scene || !scene || !player_scene->next)
        return (true);
    for (int i = 0; player; i++, player = player->next, scene[i] = NULL) {
        player_scene->next[i] = NULL;
        scene[i] = player->stat.name;
    }
    if (rpg->fight->player_scene) {
        free(rpg->fight->player_scene->av);
        free(rpg->fight->player_scene->next);
        free(rpg->fight->player_scene);
    }
    player_scene->av = scene;
    rpg->fight->player_scene = player_scene;
    return (false);
}

spell_t *ini_player_spell(void)
{
    spell_t *spell = malloc(sizeof(spell_t));

    if (!spell)
        return (NULL);
    spell->next = malloc(sizeof(spell_t));
    if (!spell->next)
        return (NULL);
    spell->next->next = NULL;
    spell->name = "Fire ball";
    spell->next->name = "Heal";
    spell->cost = 4;
    spell->next->cost = 5;
    spell->nb = 2;
    spell->next->nb = 2;
    spell->next->is_effect = true;
    spell->is_effect = false;
    spell->is_attack = true;
    spell->next->is_attack = false;
    return (spell);
}

bool init_player_sprite(player_t *player)
{
    sfIntRect rec_p = {0, 0, 270 / 9, 200 / 4};

    if (!(player->image = malloc(sizeof(img_t))))
        return (false);
    player->walk = sfClock_create();
    player->image->rect = rec_p;
    player->image->texture = \
sfTexture_createFromFile("sprite/player1.png", NULL);
    player->image->sprite = sfSprite_create();
    sfSprite_setTexture(player->image->sprite,
    player->image->texture, sfFalse);
    sfSprite_setTextureRect(player->image->sprite, rec_p);
    player->image->pos.x = WIDTH / 2 - rec_p.width / 2;
    player->image->pos.y = HEIGHT / 2 - rec_p.height / 2;
    sfSprite_setPosition(player->image->sprite, player->image->pos);
    return (true);
}

void ini_player_stat(player_t *player)
{
    player->stat.name = "Geralt";
    player->stat.is_dead = false;
    player->stat.life = 150;
    player->stat.max_life = 150;
    player->stat.min_dmg = 6;
    player->stat.max_dmg = 8;
    player->stat.mana = 20;
    player->stat.max_mana = 20;
    player->stat.xp = 0;
    player->stat.gold = 0;
    player->stat.magic_power = 1;
    player->stat.image = ini_img("sprite/player1_fight.png", v_pos(2, 2), \
ini_rect(100, 0, 30, 50), v_pos(270, 50));
}

player_t *ini_player(chain_list_t *chain_list)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->next = NULL;
    player->prev = NULL;
    chain_list->p_begin = player;
    chain_list->p_end = player;
    ini_player_stat(player);
    if (!init_player_sprite(player))
        return (NULL);
    if (!(player->spell = ini_player_spell()))
        return (NULL);
    player->level = 1;
    return (player);
}
