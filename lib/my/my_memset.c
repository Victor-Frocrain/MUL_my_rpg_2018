/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** Setup the memory
*/

#include "my.h"

char *my_memset(char c, int nb)
{
    int i = 0;
    char *str;

    if ((str = malloc(sizeof(char) * (nb + 1))) == NULL)
        return (NULL);
    for (; i < nb; i++)
        str[i] = c;
    str[nb] = 0;
    return (str);
}
