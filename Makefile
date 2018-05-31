##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC=			src/main.c			\
			src/tools/my_strncmp.c		\
			src/tools/get_next_line.c		\
			src/start_game.c		\
			src/go_to_game.c		\
			src/map/init_parralax.c		\
			src/graphic_tools/my_draw.c			\
			src/map/move_parralax.c		\
			src/event/key_pressed.c		\
			src/graphic_tools/create_obj.c		\
			src/hero/hero_animation.c			\
			src/tools/my_getstr.c			\
			src/map/load_map.c			\
			src/tools/my_str_to_word_array.c	\
			src/tools/my_getnbr.c			\
			src/graphic_tools/create_shape.c \
			src/go_to_menu.c		\
			src/menu/end_menu.c		\
			src/button/button_tools.c	\
			src/menu/init_menu.c		\
			src/menu/init_start_menu.c	\
			src/menu/init_end_menu.c	\
			src/text/text_tool.c		\
			src/text/exit_text.c		\
			src/button/button_fptr.c	\
			src/map/load_block.c		\
			src/menu/init_game_menu.c	\
			src/tools/get_flags.c			\
			src/map/set_config.c		\
			src/hero/fire_ball.c		\
			src/event/mouse_pressed.c	\
			src/event/mouse_released.c	\
			src/hero/move_fire_ball.c	\
			src/game_interaction/check_fb_colision.c	\
			src/graphic_tools/free_list.c	\

OBJ=			$(SRC:.c=.o)

NAME=			my_runner

LIB_PATH= lib/my
LIB_NAME= libmy.a

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm -g3 -I ./include


all:	$(OBJ)
	cd lib/my/generate && $(MAKE)
	gcc -o $(NAME) $(OBJ) -L $(LIB_PATH) -lmy -lc_graph_prog $(CFLAGS)

play:	$(OBJ)
	cd lib/my/generate && $(MAKE)
	gcc -o $(NAME) $(OBJ) -L $(LIB_PATH) -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f my_rpg

re:	fclean all

replay: fclean play
