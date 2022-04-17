##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for my_rpg
##

NAME         =		    my_rpg

CSFML        =          -lcsfml-graphics -lcsfml-window \
						-lcsfml-system -lcsfml-audio

INCLUDE      =         	-I include/ -I include/lib/ -L lib/ -lmy -lmyprintf \
						$(CSFML)

CFLAGS      +=         -Wall -Wextra -Werror -fvisibility=hidden $(INCLUDE)

SOURCES      =         src/

CINE		 =			cinematiques/

EVT 		 =			events/

INIT		 =			initialize/

DISP		 =			display/

PARS		 =			parser/

CLASS        =          class/

SRC          =         	$(SOURCES)main.c		                    \
						$(SOURCES)$(EVT)analyse_event.c   			\
						$(SOURCES)$(EVT)handle_click.c   			\
						$(SOURCES)$(EVT)select_key.c   				\
						$(SOURCES)$(EVT)select_movement.c  			\
						$(SOURCES)$(EVT)select_menu.c				\
						$(SOURCES)$(EVT)builtins.c   				\
						$(SOURCES)$(EVT)sliders.c   				\
						$(SOURCES)$(EVT)menu_event.c  			    \
						$(SOURCES)$(INIT)init.c   					\
						$(SOURCES)$(INIT)init_main_menu.c   		\
						$(SOURCES)$(INIT)init_game.c  				\
						$(SOURCES)$(INIT)init_pause.c  				\
						$(SOURCES)$(INIT)init_choosing.c			\
						$(SOURCES)$(INIT)init_settings.c   			\
						$(SOURCES)$(INIT)init_settings_key.c   		\
						$(SOURCES)$(INIT)init_settings_sounds.c   	\
						$(SOURCES)$(INIT)init_menu_player.c   		\
						$(SOURCES)$(INIT)init_load_menu.c   		\
						$(SOURCES)$(INIT)init_htp_first.c   		\
						$(SOURCES)$(INIT)init_htp_second.c   		\
						$(SOURCES)$(INIT)init_htp_third.c   		\
						$(SOURCES)$(INIT)init_player.c   			\
						$(SOURCES)$(DISP)draw.c   					\
						$(SOURCES)$(DISP)draw_settings.c   			\
						$(SOURCES)$(DISP)display_settings.c   		\
						$(SOURCES)$(DISP)display.c   				\
						$(SOURCES)$(DISP)popup.c	   				\
						$(SOURCES)$(DISP)display_htp.c   			\
						$(SOURCES)$(DISP)display_key_with_pnj.c		\
						$(SOURCES)$(DISP)display_menu_player.c		\
						$(SOURCES)$(DISP)loading.c					\
						$(SOURCES)$(PARS)parser.c   				\
						$(SOURCES)$(PARS)update_file.c   				\
						$(SOURCES)$(CINE)intro.c   					\
						$(SOURCES)$(CINE)init_intro.c   			\
						$(SOURCES)$(CINE)draw_intro.c   			\
						$(SOURCES)$(CINE)draw_outro.c   			\
						$(SOURCES)$(CINE)enter_battle.c				\
						$(SOURCES)$(CINE)fight_battle.c				\
						$(SOURCES)$(CINE)outro.c                    \
						$(SOURCES)$(CLASS)chevalier.c               \
						$(SOURCES)$(CLASS)cuisiniere.c              \
						$(SOURCES)$(CLASS)archere.c        	        \
						$(SOURCES)$(CLASS)mage.c        	        \
						$(SOURCES)$(CLASS)valkyrie.c       	        \
						$(SOURCES)$(CLASS)arbaletier.c

SRC_COUNT    =         $(words $(SRC))

NB           =         0

OBJ          =	        $(SRC:.c=.o)

TEMPFILES    =         *~ *vgcore* #*#

RM           =         rm -f

ECHO         =         /bin/echo -e
DEFAULT      =         "\033[00m"
BOLD         =         "\e[1m"
RED          =         "\e[31m"
GREEN        =         "\e[32m"
LIGHT_BLUE   =         "\e[94m"
WHITE        =         "\e[1;37m"

all:	$(NAME)

$(NAME):	$(OBJ)
			@echo
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"SRC files sucessfully build. "$(DEFAULT))
			@make -C lib/my/ --no-print-directory
			@make -C lib/myprintf/ --no-print-directory
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) \
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

debug:		CFLAGS += -g3 -pg
debug:		all

clean:
			@make -C lib/my/ clean --no-print-directory
			@make -C lib/myprintf/ clean --no-print-directory
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@make -C lib/myprintf/ fclean --no-print-directory
			@make -C lib/my/ fclean --no-print-directory
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

re:
			@make fclean --no-print-directory
			@make --no-print-directory

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && python3 build/build.py $< $(NB) \
			$(SRC_COUNT)

.PHONY: all re clean fclean debug
