/*
** EPITECH PROJECT, 2019
** destroy_fight.c
** File description:
** destroy_fight.c
*/

#include "rpg.h"

void free_scene(fight_scene_t *scene)
{
    if (scene->av)
        free(scene->av);
}

void destroy_rec(fight_scene_t *scene)
{
    for (int i = 0; scene->next[i]; i++)
        destroy_rec(scene->next[i]);
    free_scene(scene);
}

void destroy_fight(fight_t *fight)
{
    if (fight) {}
    destroy_image(fight->background, 1);
    destroy_text(fight->text);
    free(fight);
}
