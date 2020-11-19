/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** fill_stat.c
*/

#include "rpg.h"

bool fill_range(char *str, int *min, int *max)
{
    int i = 0;

    for (; str[i] && str[i] != '-'; i++);
    if (str[i] != '-')
        return (false);
    str[i] = 0;
    (*min) = my_getnbr(str);
    (*max) = my_getnbr(str + i + 1);
    return (true);
}

int get_random_from_range(int min, int max)
{
    return (rand() / (RAND_MAX / (max - min + 1)) + min);
}

void ini_enemy_sprite(char *str, stat_t *stat, fight_t *fight)
{
    char *width = str + my_strlen(str) + 1;
    char *height = width + my_strlen(width) + 1;
    char *sizex = height + my_strlen(height) + 1;

    (*stat).image = ini_img(fight->enemy_path[my_getnbr(str)], \
v_pos(2, 2), ini_rect(0, 0, \
my_getnbr(width), my_getnbr(height)), v_pos(my_getnbr(sizex), 100));
    (*stat).effect = NULL;
}

bool fill_stat_from_file(char *str, stat_t *stat, game_t *game)
{
    int min;
    int max;
    char *life = str + my_strlen(str) + 1;
    char *dmg = life + my_strlen(life) + 1;
    char *xp = dmg + my_strlen(dmg) + 1;
    char *gold = xp + my_strlen(xp) + 1;

    ini_enemy_sprite(gold + my_strlen(gold) + 1, stat, game->rpg->fight);
    (*stat).name = str;
    if (!fill_range(life, &min, &max))
        return (false);
    (*stat).life = get_random_from_range(min, max);
    (*stat).max_life = (*stat).life;
    if (!fill_range(dmg, &(*stat).min_dmg, &(*stat).max_dmg))
        return (false);
    if (!fill_range(gold, &min, &max))
        return (false);
    (*stat).gold = get_random_from_range(min, max);
    (*stat).is_dead = false;
    (*stat).xp = my_getnbr(xp);
    return (true);
}

bool fill_stat(stat_t *stat, int type, game_t *game)
{
    int fd = open(ENEMY_PATH, O_RDONLY);
    char *s;
    int count = 0;

    if (fd < 0)
        return (false);
    for (s = get_next_line(fd); s && count != type; count++) {
        free(s);
        s = get_next_line(fd);
    }
    if (count != type || !is_enemy_line_correct(s) || \
        !fill_stat_from_file(s, stat, game))
        return (false);
    return (true);
}
