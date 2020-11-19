/*
** EPITECH PROJECT, 2019
** map_elem
** File description:
** map_elem
*/

#include "rpg.h"

void init_map_sprites(game_t *game)
{
    sfVector2f pos = {0, HEIGHT - 135};
    sfFloatRect bounds;

    for (int i = 0; i < NB_ELEM; i++) {
        game->rpg->map->elem[i]->sprite = sfSprite_create();
        sfSprite_setTexture(game->rpg->map->elem[i]->sprite,
        game->rpg->map->elem[i]->texture, sfFalse);
    }
    bounds = sfSprite_getGlobalBounds(game->rpg->map->elem[choice]->sprite);
    pos.x = WIDTH / 2 - bounds.width / 2;
    sfSprite_setPosition(game->rpg->map->elem[choice]->sprite, pos);
}

void init_map_textures_next_after(game_t *game)
{
    game->rpg->map->elem[house2]->texture = sfTexture_createFromFile
    ("sprite/house2.png", NULL);
    game->rpg->map->elem[inn]->texture = sfTexture_createFromFile
    ("sprite/inn.png", NULL);
    game->rpg->map->elem[dragon]->texture = sfTexture_createFromFile
    ("sprite/dragon_map.png", NULL);
}

void init_map_textures_after(game_t *game)
{
    game->rpg->map->elem[table]->texture = sfTexture_createFromFile
    ("sprite/table.png", NULL);
    game->rpg->map->elem[stool]->texture = sfTexture_createFromFile
    ("sprite/stool.png", NULL);
    game->rpg->map->elem[stalagmite]->texture = sfTexture_createFromFile
    ("sprite/stalagmite.png", NULL);
    game->rpg->map->elem[water]->texture = sfTexture_createFromFile
    ("sprite/water.png", NULL);
    game->rpg->map->elem[fog]->texture = sfTexture_createFromFile
    ("sprite/fog.png", NULL);
    game->rpg->map->elem[road]->texture = sfTexture_createFromFile
    ("sprite/road.png", NULL);
    game->rpg->map->elem[house_wall]->texture = sfTexture_createFromFile
    ("sprite/wall_inn.png", NULL);
    game->rpg->map->elem[house_ground]->texture = sfTexture_createFromFile
    ("sprite/house_ground.png", NULL);
    game->rpg->map->elem[house1]->texture = sfTexture_createFromFile
    ("sprite/house1.png", NULL);
    init_map_textures_next_after(game);
}

void init_map_textures_next(game_t *game)
{
    game->rpg->map->elem[c_wall]->texture = sfTexture_createFromFile
    ("sprite/wall_church.png", NULL);
    game->rpg->map->elem[chair]->texture = sfTexture_createFromFile
    ("sprite/chair_church.png", NULL);
    game->rpg->map->elem[g_church]->texture = sfTexture_createFromFile
    ("sprite/font_church.png", NULL);
    game->rpg->map->elem[g_cave]->texture = sfTexture_createFromFile
    ("sprite/cave_ground.png", NULL);
    game->rpg->map->elem[back_text]->texture = sfTexture_createFromFile
    ("sprite/back_text.png", NULL);
    game->rpg->map->elem[map_daemon]->texture = sfTexture_createFromFile
    ("sprite/map_daemon.png", NULL);
    game->rpg->map->elem[innkeeper]->texture = sfTexture_createFromFile
    ("sprite/innkeeper.png", NULL);
    game->rpg->map->elem[choice]->texture = sfTexture_createFromFile
    ("sprite/choice.png", NULL);
    game->rpg->map->elem[bed]->texture = sfTexture_createFromFile
    ("sprite/bed.png", NULL);
    init_map_textures_after(game);
}

void init_map_textures(game_t *game)
{
    for (int i = 0; i < NB_ELEM; i++)
        game->rpg->map->elem[i] = malloc(sizeof(img_t));
    game->rpg->map->elem[bloc]->texture = sfTexture_createFromFile
    ("sprite/bloc.jpg", NULL);
    game->rpg->map->elem[grass]->texture = sfTexture_createFromFile
    ("sprite/grass.jpg", NULL);
    game->rpg->map->elem[grass2]->texture = sfTexture_createFromFile
    ("sprite/grass2.png", NULL);
    game->rpg->map->elem[vendor]->texture = sfTexture_createFromFile
    ("sprite/vendor.png", NULL);
    game->rpg->map->elem[tree]->texture = sfTexture_createFromFile
    ("sprite/tree.png", NULL);
    game->rpg->map->elem[fir]->texture = sfTexture_createFromFile
    ("sprite/fir.png", NULL);
    game->rpg->map->elem[church]->texture = sfTexture_createFromFile
    ("sprite/church_front.png", NULL);
    game->rpg->map->elem[c_back]->texture = sfTexture_createFromFile
    ("sprite/church_background.png", NULL);
    init_map_textures_next(game);
    init_map_sprites(game);
}
