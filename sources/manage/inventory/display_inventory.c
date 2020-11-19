/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** draw inventory
*/

#include "../../../include/rpg.h"

void draw_inventory(game_t *game, img_t img)
{
    sfSprite_setPosition(img.sprite, img.pos);
    sfSprite_setTextureRect(img.sprite, img.rect);
    sfRenderWindow_drawSprite(game->window, img.sprite, NULL);
}

void draw_background(game_t *game)
{
    draw_inventory(game, game->rpg->inv->image[1]);
    draw_inventory(game, game->rpg->inv->image[4]);
    draw_inventory(game, game->rpg->inv->image[7]);
}

void draw_skill_tree(game_t *game)
{
    draw_inventory(game, game->rpg->inv->image[2]);
    draw_inventory(game, game->rpg->inv->image[3]);
    draw_inventory(game, game->rpg->inv->image[6]);
}

void display_inventory(game_t *game)
{
    sfVector2f pos = {545, 850};
    static bool is_realeased = true;

    if (sfKeyboard_isKeyPressed(sfKeyI) && is_realeased) {
        game->rpg->inv->is_pressed = !game->rpg->inv->is_pressed;
        is_realeased = false;
    }
    if (!is_realeased && !sfKeyboard_isKeyPressed(sfKeyI))
        is_realeased = true;
    if (game->rpg->inv->is_pressed) {
        draw_background(game);
        for (int i = 0; i < 6; i++) {
            pos.x += i + 120;
            sfSprite_setPosition(game->rpg->inv->image[5].sprite, pos);
            sfRenderWindow_drawSprite
            (game->window, game->rpg->inv->image[5].sprite, NULL);
        }
        draw_inventory(game, game->rpg->inv->image[0]);
        draw_skill_tree(game);
    }
}
