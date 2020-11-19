/*
** EPITECH PROJECT, 2019
** ini music
** File description:
** ini music function
*/

#include "rpg.h"

sfMusic **ini_music(void)
{
    sfMusic **music = malloc(sizeof(sfMusic *) * NB_SOUND);

    if (music) {
        music[0] = sfMusic_createFromFile("sound/menu.ogg");
        music[1] = sfMusic_createFromFile("sound/combat.ogg");
        music[2] = sfMusic_createFromFile("sound/map.ogg");
    }
    sfMusic_setLoop(music[0], true);
    sfMusic_setLoop(music[1], true);
    sfMusic_setLoop(music[2], true);
    return (music);
}
