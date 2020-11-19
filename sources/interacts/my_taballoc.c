/*
** EPITECH PROJECT, 2019
** my_taballoc
** File description:
** my_taballoc
*/

#include "../../include/rpg.h"

char **my_taballoc(char **tab, int fd)
{
    char **result = NULL;
    int len = 0;

    for (len = 0; tab && tab[len]; len++);
    if ((result = malloc(sizeof(char *) * (len + 2))) == NULL)
        return (NULL);
    for (int i = 0; i < len && tab && tab[i]; i++)
        result[i] = my_strcpy(tab[i]);
    result[len] = get_next_line(fd);
    result[len + 1] = NULL;
    return (result);
}
