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

SRC          =         	$(SOURCES)main.c			\
						$(SOURCES)$(EVT)analyse_event.c   \
						$(SOURCES)$(EVT)handle_click.c   \
						$(SOURCES)$(EVT)builtins.c   \
						$(SOURCES)$(EVT)menu_event.c   \
						$(SOURCES)$(INIT)init.c   \
						$(SOURCES)$(INIT)init_main_menu.c   \
						$(SOURCES)$(INIT)init_game.c   \
						$(SOURCES)$(DISP)draw.c   \
						$(SOURCES)$(DISP)display.c   \
						$(SOURCES)$(CINE)intro.c   \
						$(SOURCES)$(CINE)outro.c

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
