/*
** EPITECH PROJECT, 2019
** ini_rpg.c
** File description:
** ini_rpg.c
*/

#include "rpg.h"

img_t *init_back_win(void)
{
    img_t *back = malloc(sizeof(img_t));

    back->texture = sfTexture_createFromFile("sprite/back_win.png", NULL);
    back->sprite = sfSprite_create();
    sfSprite_setTexture(back->sprite, back->texture, sfFalse);
    return (back);
}

sfText *ini_congrats(void)
{
    sfVector2f pos = {0, HEIGHT / 2.5};
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("sprite/Navilla.ttf");
    sfFloatRect bounds;

    sfText_setFont(text, font);
    sfText_setString(text, "CONGRATULATIONS !\nYou saved the world.");
    sfText_setCharacterSize(text, 50);
    bounds = sfText_getGlobalBounds(text);
    pos.x = WIDTH / 2 - bounds.width / 2;
    sfText_setPosition(text, pos);
    return (text);
}

int ini_nb_enemy(void)
{
    int count = 0;
    int fd = open(ENEMY_PATH, O_RDONLY);

    if (fd < 0)
        return (-1);
    for (char *s = get_next_line(fd); s; count++) {
        free(s);
        s = get_next_line(fd);
    }
    close(fd);
    return (count);
}

rpg_t *ini_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (!rpg || !(rpg->chain_list = ini_chain_list()) || \
(rpg->nb_enemy = ini_nb_enemy()) <= 0)
        return (NULL);
    rpg->player = rpg->chain_list->p_begin;
    rpg->fight = NULL;
    rpg->inv = ini_inv();
    rpg->last_fight = -10000;
    rpg->is_fighting = false;
    rpg->is_game_over = false;
    rpg->win = false;
    rpg->back = init_back_win();
    rpg->congrats = ini_congrats();
    return (rpg);
}
