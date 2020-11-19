/*
** EPITECH PROJECT, 2018
** rpg.h
** File description:
** rpg.h
*/

#ifndef RPG_H_
#define RPG_H_

#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "struct.h"

#define SOUND (true)
#define ENEMY_PATH ("stat/enemy.txt")

int rpg(void);
/*
** Save
*/
void load_save(game_t *game, char *filepath);
player_t *load_first_player(game_t *game, char *str);
player_t *load_player(game_t *game, char *str);
bool check_nb_info(char *str, int nb);
int my_get_int_in_str(char *str, int nb);
char *my_get_str_in_str(char *str, int nb);
char *my_get_str_fd(char *filepath, int nb);
void new_button_management(game_t *game, int i);
void load_button_management(game_t *game, int i);
void load_player_stat(player_t *player, char *str);
/*
** Save
*/
/* 
** Initializer
*/
game_t *ini_game(void);
menu_t ini_menu(void);
rpg_t *ini_rpg(void);
fight_t *ini_fight(void);
player_t *ini_player(chain_list_t *chain_list);
chain_list_t *ini_chain_list(void);
sfMusic **ini_music(void);
/* 
** Initializer
*/
/* 
** Ini CSFML
*/
sfIntRect ini_rect(int left, int top, int width, int height);
sfVector2f v_pos(float x, float y);
sfVector2u vu_pos(int x, int y);
img_t ini_img(char *filepath, sfVector2f scale, sfIntRect rect,
sfVector2f size);
/* 
** Ini CSFML
*/
/* 
** Destroy function
*/
void destroy_player(chain_list_t *chain_list);
void destroy_enemy(chain_list_t *chain_list);
void destroy_chain_list(chain_list_t *chain_list);
void destroy_text(text_t text);
void destroy_image(img_t *img, int nb_img);
void destroy_game(game_t *game);
void destroy_menu(game_t *game);
void destroy_rpg(game_t *game);
void destroy_fight(fight_t *fight);
bool remove_enemy(game_t *game, enemy_t *enemy);
void remove_entity_turn(game_t *game, stat_t stat);
/* 
** Destroy function
*/

/*          Display function          */

/*
** Display CSFML
*/
void display_text(char *str, game_t *game, sfVector2f pos);
bool display_text_rate(stat_t stat, game_t *game, sfVector2f pos);
void display_fight(game_t *game);
void display_fight_text(game_t *game, char **av);
void display_next_anim(img_t *img, game_t *game, int clock);
/*
** Display CSFML
*/
/*
** Display element
*/
void display_turn(game_t *game);
void display_xp_during_fight(player_t *player, game_t *game, sfVector2f pos);
void display_empty_bar(game_t *game, sfVector2f pos, img_t *background, \
sfVector2f scale);
void display_fighter(game_t *game);
void display_mana(stat_t stat, game_t *game, sfVector2f pos);
void display_element(game_t *game, img_t img);
void display_map(game_t *game, char **map);
void display_church(game_t *game, char c, sfVector2f pos);
void display_trees(game_t *game, char c, sfVector2f pos);
/*
** Display element
*/
/* Menu */
void display_pause(game_t *game);
void parrallax_cloud(game_t *game, img_t *img, float speed);
void display_background_menu(game_t *game);
void refresh_menu(game_t *game);
void refresh_usage(game_t *game);
void refresh_new(game_t *game);
void refresh_load(game_t *game);
void text_save(game_t *game);
void print_text_menu(game_t *game, char *str, sfVector2f pos, int size);
/*
** Menu
*/

/*          Display function          */

/*                   General Function            */

/* 
** Manage map
*/
char **my_taballoc(char **tab, int fd);
void init_files(game_t *game);
void init_nb_links(game_t *game);
room_t *init_struct(game_t *game, int i, room_t *room, room_t *prev);
game_t *init_maps(game_t *game);
void init_files(game_t *game);
bool check_vertical(game_t *game, int i, int j, int move);
bool check_horizontal(game_t *game, int i, int j, int move);
bool manage_collisions(game_t *game, int move);
void manage_interacts(game_t *game);
void manage_map(game_t *game);
bool manage_move(game_t *game);
int count_links(char **map);
void init_map_textures(game_t *game);
void animate_player(game_t *game);
bool turn_vertical(game_t *game, int key);
void turn_horizontal(game_t *game, int key);
void turn_player(game_t *game, int key);
void go_fight(game_t *game, char c, int i, int j);
bool detect_block(game_t *game, int i, int j);
/* 
** Manage map
*/
bool is_fight_winned(game_t *game);
bool creating_enemy_scene(game_t *game, int enemy_count);
order_t *ini_order(chain_list_t *chain_list);
void link_enemy_to_chain_list(game_t *game, enemy_t *enemy);
enemy_t *find_enemy_attacked(game_t *game, int target);
char *new_rate(int hp, char *rate, char *map_hp);
char *get_rate(char *str, char *str2, char *old_rate);
char *my_getstr(int nb);
bool is_str_dif_int(char *str, int nb);
void curse_event(game_t *game, bool *is_key_pressed,
void (*func)(game_t *game, int key));
int count_arg(char **av);
bool create_enemy(game_t *game);
bool engage_fight(game_t *game);
bool manage_fight_action(char *name, int target, game_t *game);
sfColor set_color(int red, int green, int blue, int alpha);
bool fill_stat(stat_t *stat, int type, game_t *game);
bool is_enemy_line_correct(char *str);
void manage_turn(game_t *game);
void manage_hud_move(game_t *game, int key);
bool is_same_stat(stat_t stat1, stat_t stat2);
void manage_end_fight(game_t *game);
int get_xp_lvl_up(player_t *player);
void manage_lvl_up(player_t *player);
bool next_turn(game_t *game);
bool manage_spell(game_t *game, int target);
bool is_pos_under_square(sfVector2f pos, sfVector2f t_left, sfVector2f d_right);
bool test_rect(img_t *img, sfVector2f mouse, int i, int j);
bool test_rect_fix_rect(img_t *img, sfVector2f mouse, int i, int j);
int my_int_len(int nb);
bool create_spell_scene(game_t *game, stat_t *stat);
player_t *find_stat_player(chain_list_t *chain_list, stat_t *stat);
void manage_effect(stat_t *stat, effect_t *effect);
void display_fight_sprite(chain_list_t *chin_list, game_t *game);
void send_effect(effect_t *effect, stat_t *stat);
bool display_level(game_t *game, player_t *player, sfVector2f pos);
bool ini_player_fight_scene(rpg_t *rpg);
player_t *find_player_targetted(chain_list_t *chain_list, int target);
bool is_end(game_t *game);
void gave_rewards_to_players(game_t *game);
spell_t *load_player_spell(char *str);
/* 
** Manage inventory
*/
void draw_inventory(game_t *game, img_t img);
img_t *init_slot(void);
inv_t *ini_inv(void);
void display_inventory(game_t *game);
/*
** manage particle
*/
pixels_t *init_sparks(void);
pixels_t *init_particles(void);
void manage_particles(game_t *game);
void manage_sparks(game_t *game);
/*
** manage pnj
*/
pnj_t *init_pnj(void);
void manage_pnj(game_t *game, int i, int j, char **map);
void init_text(game_t *game);
void change_text_params(game_t *game, int i);
void display_talk(game_t *game, int *diff);
bool engage_boss(game_t *game, int enemy_id);
void interact_with_boss(game_t *game, int progress, int i, int j);
void disapear_boss(game_t *game);
int manage_innkeeper(game_t *game);
void display_boss(game_t *game, char c, sfVector2f pos);
void manage_choice(game_t *game, int *top);
void check_decision(game_t *game, int top, int *diff);
void display_in_house(game_t *game, char c, sfVector2f pos);
void display_win(game_t *game);
void display_dial(game_t *game, sfText *text);

/*                   General Function            */

#endif /* RPG_H_ */
