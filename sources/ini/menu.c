/*
** EPITECH PROJECT, 2019
** menu
** File description:
** menu function
*/

#include "rpg.h"

void next_next_image(img_t *image)
{
    image[16] = ini_img("sprite/key_left.png", v_pos(4, 4),
    ini_rect(0, 0, 11, 13), v_pos(11, 13));
    image[17] = ini_img("sprite/key_e.png", v_pos(4, 4),
    ini_rect(0, 0, 11, 13), v_pos(11, 13));
    image[18] = ini_img("sprite/key_space.png", v_pos(4, 4),
    ini_rect(0, 0, 11, 13), v_pos(11, 13));
    image[19] = ini_img("sprite/background_pause.png", v_pos(100, 100),
    ini_rect(0, 0, 20, 10), v_pos(20, 10));
    image[20] = ini_img("sprite/pause.png", v_pos(4, 4),
    ini_rect(0, 0, 400, 20), v_pos(400, 20));
}

void next_image(img_t *image)
{
    image[7] = ini_img("sprite/dragon_fantasy.png", v_pos(5, 5),
    ini_rect(0, 0, 200, 50), v_pos(200, 50));
    image[8] = ini_img("sprite/cursor.png", v_pos(2, 2),
    ini_rect(0, 0, 20, 20), v_pos(200, 20));
    image[9] = ini_img("sprite/save_font.png", v_pos(2, 2),
    ini_rect(0, 0, 400, 100), v_pos(400, 100));
    image[10] = ini_img("sprite/save_font.png", v_pos(2, 2),
    ini_rect(0, 0, 400, 100), v_pos(400, 100));
    image[11] = ini_img("sprite/save_font.png", v_pos(2, 2),
    ini_rect(0, 0, 400, 100), v_pos(400, 100));
    image[12] = ini_img("sprite/menu.png", v_pos(4, 4),
    ini_rect(0, 0, 60, 15), v_pos(180, 15));
    image[13] = ini_img("sprite/key_up.png", v_pos(4, 4),
    ini_rect(0, 0, 11, 13), v_pos(11, 13));
    image[14] = ini_img("sprite/key_down.png", v_pos(4, 4),
    ini_rect(0, 0, 11, 13), v_pos(11, 13));
    image[15] = ini_img("sprite/key_right.png", v_pos(4, 4),
    ini_rect(0, 0, 11, 13), v_pos(11, 13));
    next_next_image(image);
}

img_t *ini_image(void)
{
    img_t *image;

    if (!(image = malloc(sizeof(img_t) * MENU_IMG)))
        return (NULL);
    image[0] = ini_img("sprite/new_game.png", v_pos(4, 4),
    ini_rect(0, 0, 60, 15), v_pos(180, 15));
    image[1] = ini_img("sprite/load_game.png", v_pos(4, 4),
    ini_rect(0, 0, 60, 15), v_pos(180, 15));
    image[2] = ini_img("sprite/usage.png", v_pos(4, 4),
    ini_rect(0, 0, 60, 15), v_pos(180, 15));
    image[3] = ini_img("sprite/quit.png", v_pos(4, 4),
    ini_rect(0, 0, 60, 15), v_pos(180, 15));
    image[4] = ini_img("sprite/Background_menu.png", v_pos(4, 4),
    ini_rect(0, 0, 480, 243), v_pos(1920, 243));
    image[5] = ini_img("sprite/Cloud_menu.png", v_pos(4, 4),
    ini_rect(0, 0, 480, 243), v_pos(480, 243));
    image[6] = ini_img("sprite/Cloud_menu.png", v_pos(4, 4),
    ini_rect(0, 0, 480, 243), v_pos(480, 243));
    next_image(image);
    return (image);
}

menu_t menu_ini_pause(menu_t menu)
{
    for (int i = 0; i < 4; i++)
        menu.image[i].pos = v_pos(1400, 250 + i * 150);
    menu.image[4].pos = v_pos(0, 0);
    menu.image[5].pos = v_pos(0, 0);
    menu.image[6].pos = v_pos(-1920, 0);
    menu.image[7].pos = v_pos(100, 350);
    menu.image[9].pos = v_pos(950, 150);
    menu.image[10].pos = v_pos(950, 400);
    menu.image[11].pos = v_pos(950, 650);
    menu.image[12].pos = v_pos(100, 850);
    menu.image[19].pos = v_pos(0, 0);
    menu.image[20].pos = v_pos(160, 445);
    for (int j = 13; j < 19; j++)
        menu.image[j].pos = v_pos(950, 100 + (j - 13) * 125);
    return (menu);
}

menu_t ini_menu(void)
{
    menu_t menu;

    menu.image = ini_image();
    menu = menu_ini_pause(menu);
    menu.text = sfText_create();
    menu.font = sfFont_createFromFile("sprite/Navilla.ttf");
    sfText_setFont(menu.text, menu.font);
    menu.is_pressed = false;
    menu.pos = -1;
    menu.target = 0;
    return (menu);
}
