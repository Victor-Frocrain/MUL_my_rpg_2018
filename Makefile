##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	sources/ini/game.c				\
		sources/ini/music.c				\
		sources/ini/menu.c				\
		sources/ini/rpg.c				\
		sources/ini/player.c				\
		sources/ini/csfml_func.c			\
		sources/ini/fight.c				\
		sources/ini/chain_list.c			\
		sources/destroy/game.c				\
		sources/destroy/csfml.c				\
		sources/destroy/fight.c				\
		sources/destroy/player.c			\
		sources/destroy/enemy.c				\
		sources/destroy/chain_list.c			\
		sources/destroy/menu.c				\
		sources/destroy/rpg.c				\
		sources/windows/game.c				\
		sources/windows/pause.c				\
		sources/windows/load.c				\
		sources/windows/new.c				\
		sources/windows/menu.c				\
		sources/windows/menu/display_background_menu.c	\
		sources/windows/menu/refresh.c			\
		sources/windows/menu/text_save.c		\
		sources/windows/usage.c				\
		sources/windows/fight.c				\
		sources/windows/fight/fight_text.c		\
		sources/windows/fight/fight_hp.c		\
		sources/windows/fight/sprite.c			\
		sources/windows/display_element.c		\
		sources/animate_sprite_sheet.c			\
		sources/count_arg.c				\
		sources/rpg.c					\
		sources/manage/spell_effect.c			\
		sources/manage/fight_action.c			\
		sources/manage/turn.c				\
		sources/manage/start_fight.c			\
		sources/manage/create_fight_scene.c		\
		sources/manage/create_enemy.c			\
		sources/manage/curse_event.c			\
		sources/manage/my_getstr.c			\
		sources/manage/fill_stat.c			\
		sources/manage/end_fight.c			\
		sources/manage/xp.c				\
		sources/manage/level.c				\
		sources/manage/mana.c				\
		sources/interacts/count_links.c			\
		sources/interacts/display_map.c			\
		sources/interacts/init_files.c			\
		sources/interacts/init_maps.c			\
		sources/interacts/manage_collisions.c		\
		sources/interacts/manage_interacts.c		\
		sources/interacts/manage_move.c			\
		sources/interacts/my_taballoc.c			\
		sources/interacts/animate_player.c		\
		sources/interacts/go_fight.c			\
		sources/ini/map_elem.c				\
		sources/particules/particles.c			\
		sources/interacts/detect_block.c		\
		sources/interacts/manage_pnj.c			\
		sources/interacts/display_height.c		\
		sources/ini/init_pnj.c				\
		sources/ini/init_text.c				\
		sources/ini/init_inventory.c			\
		sources/manage/inventory/display_inventory.c	\
		sources/save/my_get_str_fd.c			\
		sources/save/load_save.c			\
		sources/save/load_player.c			\
		sources/interacts/manage_text.c			\
		sources/interacts/interact_with_boss.c		\
		sources/interacts/manage_innkeeper.c		\
		sources/interacts/display_boss.c		\
		sources/interacts/display_extend_map.c		\
		sources/interacts/display_win.c			\
		sources/windows/new_button_management.c		\
		sources/windows/load_button_management.c	\
		sources/manage/manage_end_fight.c		\
		sources/save/load_player_spell.c		\
		sources/save/load_player_stat.c			\
		sources/particules/sparks.c			\

SRC_MAIN=	sources/main.c		\

SRC_TEST=	tests/

OBJ	=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o)

NAME	=	my_rpg

TEST_NAME=	unit_tests

CFLAGS	=	-I ./include/ -W -Wall -Wextra -Wshadow

CC	=	gcc

TEST_FLAGS=	-lcriterion --coverage

LDFLAGS	=	-L lib/ -lmy -lmy-printf -lget-next-line -lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/my_printf
	make -C lib/get_next_line
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C lib/my clean
	make -C lib/my_printf clean
	make -C lib/get_next_line clean
	$(RM) $(OBJ)

fclean:		clean
	make -C lib/my fclean
	make -C lib/my_printf fclean
	make -C lib/get_next_line fclean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re:		fclean all

tests_run:
	make -C lib/my/
	make -C lib/my_printf/
	$(CC) -o $(TEST_NAME) -I include $(SRC_TEST) $(SRC) $(TEST_FLAGS) $(LDFLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests
