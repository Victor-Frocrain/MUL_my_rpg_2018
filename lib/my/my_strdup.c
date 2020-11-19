/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** Allocate a space for a string
*/

#include "my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (; str[i]; i++)
        result[i] = str[i];
    result[i] = 0;
    return (result);
}
