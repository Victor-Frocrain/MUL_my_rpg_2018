/*
** EPITECH PROJECT, 2019
** oui
** File description:
** loader
*/

#ifndef LOAD_H
#define LOAD_H

#include "rpg.h"

#define NB_SAVED (5)

bool my_isnum(char const *str);
char *returnstr(char *s);

typedef struct load_s {
    char *id;
    bool is_num;
} load_t;

const load_t loader[NB_SAVED]= {
    {"money:", true},
    {"name:", false},
    {"max_hp", true},
    {"life:", true},
    {"damage:", true}
};

#endif
