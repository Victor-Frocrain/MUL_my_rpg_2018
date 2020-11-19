/*
** EPITECH PROJECT, 2019
** ini_csfml_func.c
** File description:
** ini_csfml_func.
*/

#include "rpg.h"

sfIntRect ini_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.height = height;
    rect.left = left;
    rect.top= top;
    rect.width = width;
    return (rect);
}

sfVector2f v_pos(float x, float y)
{
    sfVector2f v_pos;

    v_pos.x = x;
    v_pos.y = y;
    return (v_pos);
}

sfVector2u vu_pos(int x, int y)
{
    sfVector2u vu_pos;

    vu_pos.x = x;
    vu_pos.y = y;
    return (vu_pos);
}

sfColor set_color(int red, int green, int blue, int alpha)
{
    sfColor color = {red, green, blue, alpha};
    return (color);
}

img_t ini_img(char *filepath, sfVector2f scale, sfIntRect rect, sfVector2f size)
{
    img_t img;

    img.sprite = sfSprite_create();
    img.texture = sfTexture_createFromFile(filepath, sfFalse);
    sfSprite_setTexture(img.sprite, img.texture, sfFalse);
    sfSprite_scale(img.sprite, scale);
    img.size = size;
    img.rect = rect;
    img.scale = scale;
    img.last_anim = 0;
    img.anim = 0;
    return (img);
}
