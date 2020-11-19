/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** header for rpg structure
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

#define WIDTH (1920)
#define HEIGHT (975)
#define BITS (32)
#define MENU_IMG (21)
#define NB_SOUND (3)
#define NB_MAPS (7)
#define NB_ELEM (29)
#define OBJ (10)
#define NB_STEP (1)
#define NB_TEXT (16)
#define NB_OBJ (10)
#define NB_PIXEL (100)
#define NB_SPARK (100)

typedef struct img_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int last_anim;
    int anim;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
}img_t;

typedef struct inv_s {
    struct inv_s *next;
    struct inv_s *prev;
    bool free;
    sfVector2f pos;
    img_t *image;
    char **slot;
    char *file[NB_OBJ];
    bool is_pressed;
}inv_t;

typedef struct room_s {
    char **map;
    sfVector2f pos;
    int type;
    struct room_s **next;
    struct room_s *prev;
} room_t;

enum {
    bloc,
    grass,
    grass2,
    vendor,
    tree,
    fir,
    church,
    c_back,
    c_wall,
    chair,
    g_church,
    g_cave,
    back_text,
    map_daemon,
    innkeeper,
    choice,
    bed,
    table,
    stool,
    stalagmite,
    water,
    fog,
    road,
    house_wall,
    house_ground,
    house1,
    house2,
    inn,
    dragon
};

typedef struct map_s {
    room_t *begin;
    room_t *end;
    char *files[NB_MAPS];
    img_t *elem[NB_ELEM];
} map_t;

typedef struct menu_s {
    sfFont *font;
    sfText *text;
    img_t *image;
    bool is_pressed;
    int pos;
    int target;
}menu_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
}text_t;

typedef struct effect_s {
    char *name;
    int nb_turn;
    int force;
    struct effect_s *next;
}effect_t;

typedef struct spell_s {
    char *name;
    int nb;
    int cost;
    bool is_attack;
    bool is_effect;
    struct spell_s *next;
}spell_t;

typedef struct stat_s {
    char *name;
    bool is_dead;
    effect_t *effect;
    int gold;
    int life;
    int mana;
    int magic_power;
    int max_mana;
    int xp;
    int max_life;
    int max_dmg;
    int min_dmg;
    img_t image;
}stat_t;

typedef struct player_s {
    struct player_s *next;
    struct player_s *prev;
    stat_t stat;
    int level;
    spell_t *spell;
    sfClock *walk;
    img_t *image;
}player_t;

typedef struct enemy_s {
    struct enemy_s *next;
    struct enemy_s *prev;
    stat_t stat;
    img_t *image;
}enemy_t;

typedef struct order_s {
    stat_t *stat;
    bool is_ally;
    bool is_first;
}order_t;

typedef struct chain_list_s {
    int e_nb;
    int p_nb;
    int nb_entity;
    enemy_t *e_begin;
    enemy_t *e_end;
    player_t *p_begin;
    player_t *p_end;
}chain_list_t;

typedef struct fight_scene_s {
    struct fight_scene_s **next;
    struct fight_scene_s *prev;
    char *name;
    int target;
    char **av;
}fight_scene_t;

typedef struct fight_s {
    fight_scene_t *scene;
    fight_scene_t *first_scene;
    fight_scene_t *player_scene;
    fight_scene_t *enemy_scene;
    int turn;
    order_t *order;
    img_t *background;
    char **enemy_path;
    img_t *hud;
    int tempo;
    text_t text;
}fight_t;

typedef struct pnj_s {
    bool is_interact;
    bool is_waiting;
    bool is_pressed;
    bool is_boss;
    bool is_daemon;
    bool dragon_unlocked;
    bool is_final;
    bool step[NB_STEP];
    char *string[NB_TEXT];
    sfText *text;
    int progress;
    int pos_x;
    int pos_y;
}pnj_t;

typedef struct rpg_s {
    int money;
    int nb_enemy;
    int last_fight;
    bool is_fighting;
    bool is_game_over;
    bool win;
    chain_list_t *chain_list;
    fight_t *fight;
    player_t *player;
    inv_t *inv;
    map_t *map;
    pnj_t *pnj;
    sfText *congrats;
    img_t *back;
}rpg_t;

typedef struct pixels_s {
    unsigned int width;
    unsigned int height;
    sfClock *anim;
    sfUint8 *color;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfVector2f speed;
    float alive;
}pixels_t;

typedef struct game_s {
    int already_done;
    char *save;
    int scene;
    bool pause;
    bool invent;
    sfMusic **sound;
    menu_t menu;
    bool *is_key_pressed;
    rpg_t *rpg;
    sfEvent event;
    inv_t *inv;
    sfRenderWindow *window;
    pixels_t *pixel[NB_PIXEL];
    pixels_t *spark[NB_SPARK];
    sfFont *font;
    sfClock *clock;
}game_t;

#endif /* STRUCT_H */
