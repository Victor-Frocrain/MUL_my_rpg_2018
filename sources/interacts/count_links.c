/*
** EPITECH PROJECT, 2019
** count_links
** File description:
** count_links
*/

#include "../../include/rpg.h"

bool check_tp(char *check, char c)
{
    for (int i = 0; check && check[i]; i++)
        if (c == check[i])
            return (false);
    return (true);
}

int count_links(char **map)
{
    int j = 0;
    int k = 0;
    int links = 0;
    int len = 0;
    char *check = my_memset(0, 10);

    if (check == NULL)
        return (0);
    for (int i = 0; map && map[i] && map[i][j];) {
        if (j == 0)
            len = my_strlen(map[i]);
        (map[i][j] >= '0' && map[i][j] <= '9' && check_tp(check, map[i][j]))?\
    links++, check[k] = map[i][j], k++:0;
        j++;
        if (j >= len) {
            i++;
            j = 0;
        }
    }
    return (links);
}
