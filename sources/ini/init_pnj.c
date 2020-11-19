/*
** EPITECH PROJECT, 2019
** init_pnj
** File description:
** init_pnj
*/

#include "rpg.h"

pnj_t *init_pnj(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    if (pnj == NULL)
        return (NULL);
    pnj->is_interact = false;
    pnj->is_pressed = false;
    pnj->is_waiting = false;
    pnj->is_boss = false;
    pnj->is_daemon = false;
    pnj->dragon_unlocked = false;
    pnj->is_final = false;
    for (int i = 0; i < NB_STEP; i++)
        pnj->step[i] = false;
    return (pnj);
}
