/*
** EPITECH PROJECT, 2019
** ini_fight.c
** File description:
** ini_fight.c
*/

#include "rpg.h"

fight_scene_t *ini_fight_scene(void)
{
    fight_scene_t *scene = malloc(sizeof(fight_scene_t));

    if (!scene || !(scene->av = malloc(sizeof(char *) * 5)) ||
        !(scene->next = malloc(sizeof(fight_scene_t *) * 5)))
        return (NULL);
    scene->name = NULL;
    for (int i = 0; i < 5; i++)
        scene->next[i] = NULL;
    scene->av[0] = "Attack";
    scene->av[1] = "Spell";
    scene->av[2] = "Items";
    scene->av[3] = "Escape";
    scene->av[4] = NULL;
    scene->target = 0;
    scene->prev = NULL;
    return (scene);
}

void ini_fight_background(img_t *img)
{
    img[0] = ini_img("sprite/Fight_Interface.png",
    v_pos(4, 4), ini_rect(0, 0, 480, 243), v_pos(480, 243));
    img[1] = ini_img("sprite/cursor.png",
    v_pos(1.5, 1.5), ini_rect(0, 0, 20, 20), v_pos(200, 20));
    img[2] = ini_img("sprite/Hp.png",
    v_pos(1.9, 1.9), ini_rect(0, 0, 100, 10), v_pos(100, 10));
    img[3] = ini_img("sprite/Mana.png",
    v_pos(1.9, 1.9), ini_rect(0, 0, 100, 10), v_pos(100, 10));
    img[4] = ini_img("sprite/Empty_bar.png",
    v_pos(2, 2), ini_rect(0, 0, 100, 10), v_pos(100, 10));
    img[5] = ini_img("sprite/xp.png",
    v_pos(1, 1), ini_rect(0, 0, 50, 5), v_pos(100, 10));
    img[6] = ini_img("sprite/background_fight.png",
    v_pos(2.5, 1.5), ini_rect(0, 0, 1000, 1200), v_pos(100, 10));
    img[7] = ini_img("sprite/ground_fight.png",
    v_pos(3.2, 2), ini_rect(0, 0, 1000, 1200), v_pos(0, 500));
}

char **ini_enemy_path(void)
{
    char **enemy_path = malloc(sizeof(char *) * 7);

    if (!enemy_path)
        return (NULL);
    enemy_path[0] = "sprite/imp.png";
    enemy_path[1] = "sprite/nightmare.png";
    enemy_path[2] = "sprite/ghost.png";
    enemy_path[3] = "sprite/slime.png";
    enemy_path[4] = "sprite/daemon.png";
    enemy_path[5] = "sprite/dragon.png";
    enemy_path[6] = NULL;
    return (enemy_path);
}

fight_t *ini_fight(void)
{
    fight_t *fight = malloc(sizeof(fight_t));

    if (!fight || !(fight->background = malloc(sizeof(img_t) * 8)) \
|| !(fight->scene = ini_fight_scene()))
        return (NULL);
    if (!(fight->enemy_path = ini_enemy_path()))
        return (NULL);
    ini_fight_background(fight->background);
    fight->first_scene = fight->scene;
    fight->tempo = 0;
    fight->enemy_scene = NULL;
    fight->player_scene = NULL;
    fight->text.text = sfText_create();
    fight->text.font = sfFont_createFromFile("sprite/Navilla.ttf");
    sfText_setCharacterSize(fight->text.text, 40);
    sfText_setFont(fight->text.text, fight->text.font);
    return (fight);
}
