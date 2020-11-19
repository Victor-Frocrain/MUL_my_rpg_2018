/*
** EPITECH PROJECT, 2019
** particles
** File description:
** particles
*/

#include "rpg.h"

void update_pixel_sprite(pixels_t *pixel)
{
    for (unsigned int y = 0; y < 40; y++)
        sfTexture_updateFromPixels(pixel->texture, pixel->color, 1, 1, 0, y);
}

pixels_t *init_particles(void)
{
    pixels_t *pixel = malloc(sizeof(pixels_t));

    if (pixel == NULL)
        return (NULL);
    if ((pixel->color = malloc(sizeof(sfUint8) * 4)) == NULL)
        return (NULL);
    pixel->color[0] = 0;
    pixel->color[1] = 0;
    pixel->color[2] = 0;
    pixel->color[3] = 100;
    pixel->anim = sfClock_create();
    pixel->texture = sfTexture_create(1, 40);
    pixel->sprite = sfSprite_create();
    update_pixel_sprite(pixel);
    sfSprite_setTexture(pixel->sprite, pixel->texture, sfFalse);
    pixel->pos.x = rand() % WIDTH;
    pixel->pos.y = (rand() % 1000) * -1;
    pixel->speed.x = 0;
    pixel->speed.y = 20 + rand() % 20;
    pixel->clock = sfClock_create();
    return (pixel);
}

void manage_particles(game_t *game)
{
    for (int i = 0; i < NB_PIXEL && game->rpg->map->begin->type == 0; i++) {
        if (game->pixel[i]->pos.y >= HEIGHT) {
            game->pixel[i]->pos.y = 0;
            game->pixel[i]->pos.x = rand() % WIDTH;
            game->pixel[i]->speed.y = 20 + rand() % 20;
        }
        if (!game->pause && !game->rpg->pnj->is_interact &&
        sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->pixel[i]->clock)) > 20) {
            sfSprite_setPosition(game->pixel[i]->sprite, game->pixel[i]->pos);
            game->pixel[i]->pos.y += game->pixel[i]->speed.y;
            sfClock_restart(game->pixel[i]->clock);
        }
        sfRenderWindow_drawSprite(game->window, game->pixel[i]->sprite, NULL);
    }
}
