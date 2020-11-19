/*
** EPITECH PROJECT, 2019
** text_save
** File description:
** text_save function
*/

#include "rpg.h"

bool check_nb_info(char *str, int nb)
{
    int j = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ';')
            j++;
    if (nb <= j)
        return (true);
    return (false);
}

char *get_the_info(char *res, char *str1, int nb)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    for (; str1[i] && j < nb; i++) {
        if (str1[i] == ':') {
            j++;
            j != nb ? k = 0 : 0;
        } else
            k++;
    }
    res = malloc(sizeof(char) * k + 1);
    if (!res)
        return (NULL);
    i -= k + 1;
    for (; m < k; m++, i++)
        res[m] = str1[i];
    res[m] = '\0';
    return (res);
}

int my_get_int_in_str(char *str1, int nb)
{
    char *res = NULL;

    res = get_the_info(res, str1, nb);
    return (my_getnbr(res));
}

char *my_get_str_in_str(char *str1, int nb)
{
    char *res = NULL;

    res = get_the_info(res, str1, nb);
    return (res);
}

char *my_get_str_fd(char *filepath, int nb)
{
    int fd;
    char *str1;
    char *res = NULL;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    str1 = get_next_line(fd);
    close(fd);
    res = get_the_info(res, str1, nb);
    free(str1);
    return (res);
}
