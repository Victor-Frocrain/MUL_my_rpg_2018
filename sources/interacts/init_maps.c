/*
** EPITECH PROJECT, 2019
** init_maps
** File description:
** init_maps
*/

#include "../../include/rpg.h"

int fill_number(char *params, char *number, int i)
{
    int j = 0;

    for (j = 0; params[i] && params[i] != ':'; i++, j++)
        number[j] = params[i];
    number[j] = 0;
    return (i + 1);
}

bool init_params(room_t *room, char *params)
{
    int i = 0;
    char *number = malloc(sizeof(char) * my_strlen(params));

    if (number == NULL)
        return (false);
    i = fill_number(params, number, i);
    room->type = my_getnbr(number);
    i = fill_number(params, number, i);
    room->pos.x = (float)(my_getnbr(number) * -50 +
    (WIDTH / 2 - (270.0 / 9)));
    i = fill_number(params, number, i);
    room->pos.y = (float)(my_getnbr(number) * -50 +
    (HEIGHT / 2 - 200.0 / 4 / 2));
    free(number);
    free(params);
    return (true);
}

char **fill_map(char *path, char **params)
{
    char **map = NULL;
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return (NULL);
    (*params) = get_next_line(fd);
    if (params == NULL || (map = my_taballoc(map, fd)) == NULL) {
        close(fd);
        return (NULL);
    }
    for (int i = 0; map && map[i];) {
        if ((map = my_taballoc(map, fd)) == NULL)
            return (NULL);
        i++;
    }
    close(fd);
    return (map);
}

room_t *init_struct(game_t *game, int i, room_t *room, room_t *prev)
{
    static int j = 0;
    int links = 0;
    char *params = NULL;

    room = malloc(sizeof(room_t));
    if (room == NULL)
        return (NULL);
    room->map = fill_map(game->rpg->map->files[j], &params);
    if (init_params(room, params) == false)
        return (NULL);
    j++;
    links = count_links(room->map);
    room->prev = prev;
    room->next = NULL;
    if ((room->next = malloc(sizeof(room_t *) * links)) == NULL)
        return (NULL);
    while (i < links) {
        room->next[i] = init_struct(game, i, room->next[i], room);
        i++;
    }
    return (room);
}

game_t *init_maps(game_t *game)
{
    game->rpg->map = malloc(sizeof(map_t));
    if (game->rpg->map == NULL)
        return (NULL);
    init_files(game);
    game->rpg->map->begin = init_struct(game, 0, game->rpg->map->begin, NULL);
    init_map_textures(game);
    return (game);
}
