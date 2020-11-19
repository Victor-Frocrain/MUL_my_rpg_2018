/*
** EPITECH PROJECT, 2019
** init
** File description:
** icon
*/

#include "../../include/rpg.h"

void init_slot2(img_t *image)
{
    image[5] = ini_img("sprite/obj/slot.png", v_pos(2.0, 2.0),
    ini_rect(0, 0, 55, 55), v_pos(80, 15));
    image[6] = ini_img("sprite/obj/chest.png", v_pos(1.9, 1.9),
    ini_rect(0, 0, 16, 16), v_pos(80, 15));
    image[7] = ini_img("sprite/obj/temp.png", v_pos(1.0, 1.0),
    ini_rect(0, 0, 232, 128), v_pos(80, 15));
}

img_t *init_slot(void)
{
    img_t *image;

    if ((image = malloc(sizeof(img_t) * NB_OBJ)) == NULL)
        return (NULL);
    image[0] = ini_img("sprite/obj/simple_sword.png", v_pos(4.5, 4.5),
    ini_rect(0, 0, 16, 16), v_pos(80, 15));
    image[1] = ini_img("sprite/obj/backg.png", v_pos(1.2, 0.9),
    ini_rect(0, 0, 651, 175), v_pos(80, 15));
    image[2] = ini_img("sprite/obj/skill_tree.png", v_pos(0.9, 0.8),
    ini_rect(0, 0, 170, 170), v_pos(90, 25));
    image[3] = ini_img("sprite/obj/player_icon.png", v_pos(2.0, 2.4),
    ini_rect(0, 0, 32, 50), v_pos(80, 15));
    image[4] = ini_img("sprite/obj/back.png", v_pos(1.1, 0.7),
    ini_rect(0, 0, 225, 225), v_pos(80, 15));
    init_slot2(image);
    return (image);
}

inv_t *set_pos_inv(inv_t *inv)
{
    inv->image[0].pos = v_pos(690, 868);
    inv->image[1].pos = v_pos(640, 818);
    inv->image[2].pos = v_pos(478, 830);
    inv->image[3].pos = v_pos(400, 840);
    inv->image[4].pos = v_pos(393, 818);
    inv->image[6].pos = v_pos(543, 880);
    inv->image[7].pos = v_pos(0, 0);
    return (inv);
}

inv_t *ini_inv(void)
{
    inv_t *inv = malloc(sizeof(inv_t));

    if (!inv)
        return (NULL);
    inv->image = init_slot();
    inv = set_pos_inv(inv);
    inv->pos.x = 100;
    inv->pos.y = 100;
    inv->is_pressed = false;
    inv->free = false;
    return (inv);
}
