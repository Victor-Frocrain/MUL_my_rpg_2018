/*
** EPITECH PROJECT, 2019
** move_animated_sprite_sheet
** File description:
** animate sprite
*/

#include "rpg.h"

void display_next_anim(img_t *img, game_t *game, int clock)
{
    int size = (*img).rect.width;
    int time = sfTime_asMilliseconds(sfClock_getElapsedTime(game->clock));

    if (clock + (*img).last_anim <= time) {
        (*img).anim++;
        (*img).last_anim = time;
        if ((*img).anim * size >= (*img).size.x)
            (*img).anim = 0;
    }
    sfSprite_setTextureRect((*img).sprite, \
ini_rect((*img).anim * size, 0 , (*img).rect.width , (*img).rect.height));
    sfRenderWindow_drawSprite(game->window, (*img).sprite, NULL);
}
