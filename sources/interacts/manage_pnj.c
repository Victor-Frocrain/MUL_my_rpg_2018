/*
** EPITECH PROJECT, 2019
** manage_pnj
** File description:
** manage_pnj
*/

#include "rpg.h"

bool check_interaction_vertical(game_t *game, int i, int j, char **map)
{
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f elem = game->rpg->map->begin->pos;
    int len = my_strlen(map[i]);
    sfFloatRect bounds = sfSprite_getGlobalBounds
    (game->rpg->player->image->sprite);

    if (game->rpg->player->image->rect.top == 0 && i > 0 &&
        (float)((i + 1) * 50 + elem.y) <= (player.y) &&
        (float)((i + 1.5) * 50 + elem.y) > (player.y) &&
        (float)((j - 0.2) * 50 + elem.x) <= player.x &&
        (float)((j + 0.5) * 50 + elem.x) >= player.x)
        return (true);
    if (game->rpg->player->image->rect.top == 200 / 2 && i < len &&
        (float)((i) * 50 + elem.y) >= (player.y + bounds.height) &&
        (float)((i - 0.3) * 50 + elem.y) <= (player.y + bounds.height) &&
        (float)((j - 0.2) * 50 + elem.x) <= player.x &&
        (float)((j + 0.5) * 50 + elem.x) >= player.x)
        return (true);
    return (false);
}

bool check_if_interaction(game_t *game, int i, int j, char **map)
{
    sfVector2f player = game->rpg->player->image->pos;
    sfVector2f elem = game->rpg->map->begin->pos;
    int len = my_strlen(map[i]);
    sfFloatRect bounds = sfSprite_getGlobalBounds
    (game->rpg->player->image->sprite);

    if (game->rpg->player->image->rect.top == 200 / 4 && j > 0 &&
        (float)((j + 1) * 50 + elem.x) <= (player.x) &&
        (float)((j + 1.5) * 50 + elem.x) > (player.x) &&
        (float)((i - 0.3) * 50 + elem.y) <= player.y &&
        (float)((i + 0.3) * 50 + elem.y) >= player.y)
        return (true);
    if (game->rpg->player->image->rect.top == 200 - 200 / 4 && j < len &&
        (float)((j - 1) * 50 + elem.x) >= (player.x - bounds.width) &&
        (float)((j - 1.5) * 50 + elem.x) <= (player.x - bounds.width) &&
        (float)((i - 0.3) * 50 + elem.y) <= player.y &&
        (float)((i + 0.3) * 50 + elem.y) >= player.y)
        return (true);
    if (sfKeyboard_isKeyPressed(sfKeyE) == false)
        game->rpg->pnj->is_pressed = false;
    return (check_interaction_vertical(game, i, j, map));
}

void manage_pnj(game_t *game, int i, int j, char **map)
{
    static int diff = 0;

    if (map[i][j] == 'V' && check_if_interaction(game, i, j, map) &&
    sfKeyboard_isKeyPressed(sfKeyE) && game->rpg->pnj->is_pressed == false) {
        game->rpg->pnj->is_interact = true;
        game->rpg->pnj->is_pressed = true;
    }
    if (map[i][j] == 'I' && check_if_interaction(game, i, j, map) &&
        sfKeyboard_isKeyPressed(sfKeyE) && game->rpg->pnj->is_pressed == false)
        diff = manage_innkeeper(game);
    display_talk(game, &diff);
    if (game->rpg->pnj->is_interact == false) {
        game->rpg->pnj->progress -= diff;
        diff = 0;
        change_text_params(game, game->rpg->pnj->progress);
    }
    if (game->rpg->pnj->is_pressed && sfKeyboard_isKeyPressed(sfKeyE) == false)
        game->rpg->pnj->is_pressed = false;
}
