/*
** EPITECH PROJECT, 2019
** my_put_str.c
** File description:
** displays characters
*/

#include "my.h"

void my_putstr(char *str)
{
    if (!str)
        return;
    for (int i = 0; str && str[i]; i++)
        my_putchar(str[i]);
}
