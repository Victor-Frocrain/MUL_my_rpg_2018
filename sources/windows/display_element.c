/*
** EPITECH PROJECT, 2019
** display_element
** File description:
** display_element function
*/

#include "rpg.h"

bool is_pos_under_square(sfVector2f pos, sfVector2f t_left, sfVector2f d_right)
{
    if (pos.x >= t_left.x && pos.x <= d_right.x)
        if (pos.y >= t_left.y && pos.y <= d_right.y)
            return (true);
    return (false);
}

bool test_rect(img_t *img, sfVector2f mouse, int i, int j)
{
    if (i >= 0 && i < j && is_pos_under_square(mouse, v_pos(img[i].pos.x, \
img[i].pos.y), v_pos(img[i].pos.x + 240, img[i].pos.y + 80)))
        return (true);
    return (false);
}

bool test_rect_fix_rect(img_t *img, sfVector2f mouse, int i, int j)
{
    if (i >= 0 && i < j && is_pos_under_square(mouse, v_pos(img[i].pos.x, \
img[i].pos.y), v_pos(img[i].pos.x + img[i].size.x * img[i].scale.x, \
img[i].pos.y + img[i].size.x * img[i].scale.y)))
        return (true);
    return (false);
}

void display_element(game_t *game, img_t img)
{
    sfSprite_setPosition(img.sprite, img.pos);
    sfSprite_setTextureRect(img.sprite, img.rect);
    sfRenderWindow_drawSprite(game->window, img.sprite, NULL);
}
