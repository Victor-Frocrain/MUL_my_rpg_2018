/*
** EPITECH PROJECT, 2019
** destroy_csfml
** File description:
** destroy_csfml.c
*/

#include "rpg.h"

void destroy_text(text_t text)
{
    sfText_destroy(text.text);
    sfFont_destroy(text.font);
}

void destroy_image(img_t *img, int nb_img)
{
    for (int i = 0; i < nb_img; i++) {
        sfSprite_destroy(img->sprite);
        sfTexture_destroy(img->texture);
    }
    free(img);
}
