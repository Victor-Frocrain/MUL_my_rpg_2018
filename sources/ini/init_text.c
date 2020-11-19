/*
** EPITECH PROJECT, 2019
** init_text
** File description:
** init_text
*/

#include "rpg.h"

void set_position_back(game_t *game)
{
    sfVector2f pos;
    sfVector2f size = {1.5, 1.5};
    sfFloatRect bounds;

    sfSprite_setScale(game->rpg->map->elem[back_text]->sprite, size);
    bounds = sfSprite_getGlobalBounds(game->rpg->map->elem[back_text]->sprite);
    pos.x = WIDTH / 2 - bounds.width / 2;
    pos.y = HEIGHT - 220;
    sfSprite_setPosition(game->rpg->map->elem[back_text]->sprite, pos);
}

void init_innkeeper_text(game_t *game)
{
    game->rpg->pnj->string[NB_TEXT - 4] = my_strdup
    ("Hey ! Do you want to save game ?");
    game->rpg->pnj->string[NB_TEXT - 3] = NULL;
    game->rpg->pnj->string[NB_TEXT - 2] = my_strdup("Do you want to exit ?");
    game->rpg->pnj->string[NB_TEXT - 1] = NULL;
    set_position_back(game);
}

void init_text(game_t *game)
{
    game->rpg->pnj->text = sfText_create();
    game->rpg->pnj->progress = 0;
    sfText_setColor(game->rpg->pnj->text, sfWhite);
    sfText_setFont(game->rpg->pnj->text, game->font);
    game->rpg->pnj->string[0] = my_strdup("Oh my god !\nThere is an horrible \
daemon in the church !");
    game->rpg->pnj->string[1] = my_strdup("Please ! Help us !");
    game->rpg->pnj->string[2] = NULL;
    game->rpg->pnj->string[3] = my_strdup("You dare to challenge me ?!");
    game->rpg->pnj->string[4] = my_strdup("Ok then, you will die.");
    game->rpg->pnj->string[5] = NULL;
    game->rpg->pnj->string[6] = my_strdup("Oh thank you sir !\nYou saved us.");
    game->rpg->pnj->string[7] = my_strdup("But the dragon in the \
cave is awakened now !");
    game->rpg->pnj->string[8] = my_strdup("Please !\nKill the dragon !");
    game->rpg->pnj->string[9] = NULL;
    game->rpg->pnj->string[10] = my_strdup("GRRRRRRRRRRRRRR !");
    game->rpg->pnj->string[11] = NULL;
    init_innkeeper_text(game);
    change_text_params(game, 0);
}
