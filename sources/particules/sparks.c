/*
** EPITECH PROJECT, 2019
** sparks
** File description:
** sparks
*/

#include "rpg.h"

void create_texture_spark(pixels_t *spark)
{
    spark->texture = sfTexture_create(3, 3);
    spark->sprite = sfSprite_create();
    for (unsigned int y = 0; y < 3; y++) {
        for (unsigned int x = 0; x < 3; x++) {
            sfTexture_updateFromPixels
            (spark->texture, spark->color, 1, 1, x, y);
        }
    }
}

float pos_neg(void)
{
    int i = rand() % 2;

    if (i == 0)
        return (1);
    return (-1);
}

pixels_t *init_sparks(void)
{
    pixels_t *spark = malloc(sizeof(pixels_t));

    if (spark == NULL)
        return (NULL);
    if ((spark->color = malloc(sizeof(sfUint8) * 4)) == NULL)
        return (NULL);
    spark->color[0] = 255;
    spark->color[1] = 162;
    spark->color[2] = 0;
    spark->color[3] = 200;
    create_texture_spark(spark);
    sfSprite_setTexture(spark->sprite, spark->texture, sfFalse);
    spark->pos.x = WIDTH / 2;
    spark->pos.y = HEIGHT;
    spark->speed.x = rand() % 10 * pos_neg();
    spark->speed.y = 5 + rand() % 10;
    spark->alive = 1500 + rand() % 4000;
    spark->clock = sfClock_create();
    spark->anim = sfClock_create();
    return (spark);
}

void manage_sparks(game_t *game)
{
    for (int i = 0; i < NB_SPARK && game->pause; i++) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->spark[i]->clock)) >= game->spark[i]->alive) {
            game->spark[i]->pos.y = HEIGHT;
            game->spark[i]->pos.x = WIDTH / 2;
            game->spark[i]->speed.y = 5 + rand() % 10;
            game->spark[i]->speed.x = rand() % 10 * pos_neg();
            game->spark[i]->alive = 1500 + rand() % 4000;
            sfClock_restart(game->spark[i]->clock);
        }
        if (!game->rpg->pnj->is_interact &&
        sfTime_asMilliseconds(sfClock_getElapsedTime
        (game->spark[i]->anim)) > 20) {
            sfSprite_setPosition(game->spark[i]->sprite, game->spark[i]->pos);
            game->spark[i]->pos.y -= game->spark[i]->speed.y;
            game->spark[i]->pos.x -= game->spark[i]->speed.x;
            sfClock_restart(game->spark[i]->anim);
        }
        sfRenderWindow_drawSprite(game->window, game->spark[i]->sprite, NULL);
    }
}
