/*
** EPITECH PROJECT, 2019
** count_arg.c
** File description:
** arg counter
*/

#include "rpg.h"

int count_arg(char **av)
{
    int count = 0;

    for (; av[count]; count++);
    return (count);
}
