##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for my_rpg
##

NAME         =		    unit_tests

CSFML        =          -lcsfml-graphics -lcsfml-window \
						-lcsfml-system -lcsfml-audio

INCLUDE      =         	-I ../include/ -I ../include/lib/ \
						-L ../lib/ -lm -lmy -lmyprintf \
						$(CSFML) \
						-lcriterion --verbose --coverage \
						-fprofile-arcs -ftest-coverage

CFLAGS      +=         -Wall -Wextra -Werror -fvisibility=hidden $(INCLUDE)

SOURCES      =         ../src/

CINE		 =			cinematiques/

EVT 		 =			events/

INIT		 =			initialize/

DISP		 =			display/

PARS		 =			parser/

CLASS        =          class/

NPC			 =			npc/

FREE         =		  	free/

TESTS        =          cinematiques.c		\
						class.c        		\
						other_class.c       \
						display_menu.c      \
						display_more_menu.c \
						display.c      		\
						conc_test.c			\
						events.c        	\
						key.c   	   		\
						parser.c

SRC          =         	$(SOURCES)$(EVT)analyse_event.c   			\
						$(SOURCES)$(EVT)handle_click.c   			\
						$(SOURCES)$(EVT)button_state.c   			\
						$(SOURCES)$(EVT)check_save.c   				\
						$(SOURCES)$(EVT)load.c   					\
						$(SOURCES)$(EVT)clear.c   					\
						$(SOURCES)$(EVT)change_tab.c   				\
						$(SOURCES)$(EVT)update_character.c			\
						$(SOURCES)$(EVT)select_key.c   				\
						$(SOURCES)$(EVT)select_movement.c  			\
						$(SOURCES)$(EVT)select_action.c  			\
						$(SOURCES)$(EVT)select_menu.c				\
						$(SOURCES)$(EVT)builtins.c   				\
						$(SOURCES)$(EVT)sliders.c   				\
						$(SOURCES)$(EVT)move.c		  				\
						$(SOURCES)$(EVT)menu_event.c  			    \
						$(SOURCES)$(EVT)inventory.c  			    \
						$(SOURCES)$(INIT)init.c   					\
						$(SOURCES)$(INIT)set_player.c				\
						$(SOURCES)$(INIT)init_scenes.c				\
						$(SOURCES)$(INIT)update_stat.c				\
						$(SOURCES)$(INIT)init_main_menu.c   		\
						$(SOURCES)$(INIT)init_game.c  				\
						$(SOURCES)$(INIT)init_pause.c  				\
						$(SOURCES)$(INIT)init_choosing.c			\
						$(SOURCES)$(INIT)init_settings.c   			\
						$(SOURCES)$(INIT)init_settings_key.c   		\
						$(SOURCES)$(INIT)init_settings_frame.c		\
						$(SOURCES)$(INIT)init_settings_sounds.c   	\
						$(SOURCES)$(INIT)init_menu_player.c   		\
						$(SOURCES)$(INIT)init_load_menu.c   		\
						$(SOURCES)$(INIT)init_htp_first.c   		\
						$(SOURCES)$(INIT)init_htp_second.c   		\
						$(SOURCES)$(INIT)init_htp_third.c   		\
						$(SOURCES)$(INIT)init_player.c   			\
						$(SOURCES)$(INIT)init_inventory.c  			\
						$(SOURCES)$(INIT)init_npc.c  				\
						$(SOURCES)$(DISP)draw.c   					\
						$(SOURCES)$(DISP)draw_dialogue_box.c   		\
						$(SOURCES)$(DISP)draw_settings.c   			\
						$(SOURCES)$(DISP)display_settings.c   		\
						$(SOURCES)$(DISP)display.c   				\
						$(SOURCES)$(DISP)draw_xp_bar.c 				\
						$(SOURCES)$(DISP)set_good.c   				\
						$(SOURCES)$(DISP)get_quest.c   				\
						$(SOURCES)$(DISP)display_stat.c				\
						$(SOURCES)$(DISP)display_load.c				\
						$(SOURCES)$(DISP)set_settings.c				\
						$(SOURCES)$(DISP)popup.c	   				\
						$(SOURCES)$(DISP)display_htp.c   			\
						$(SOURCES)$(DISP)display_key_with_pnj.c		\
						$(SOURCES)$(DISP)display_menu_player.c		\
						$(SOURCES)$(DISP)display_inventory.c		\
						$(SOURCES)$(DISP)display_npc.c				\
						$(SOURCES)$(DISP)loading.c					\
						$(SOURCES)$(PARS)parser.c   				\
						$(SOURCES)$(PARS)type_json.c   				\
						$(SOURCES)$(PARS)update_file.c   			\
						$(SOURCES)$(PARS)update_inventory.c			\
						$(SOURCES)$(CINE)intro.c   					\
						$(SOURCES)$(CINE)init_intro.c   			\
						$(SOURCES)$(CINE)draw_intro.c   			\
						$(SOURCES)$(CINE)draw_outro.c   			\
						$(SOURCES)$(CINE)enter_battle.c				\
						$(SOURCES)$(CINE)fight_battle.c				\
						$(SOURCES)$(CINE)outro.c                    \
						$(SOURCES)$(FREE)free_all.c                 \
						$(SOURCES)$(FREE)free_player.c              \
						$(SOURCES)$(FREE)free_scenes.c              \
						$(SOURCES)$(CLASS)chevalier.c               \
						$(SOURCES)$(CLASS)cuisiniere.c              \
						$(SOURCES)$(CLASS)archere.c        	        \
						$(SOURCES)$(CLASS)mage.c        	        \
						$(SOURCES)$(CLASS)valkyrie.c       	        \
						$(SOURCES)$(CLASS)arbaletier.c				\
						$(SOURCES)$(NPC)check_npc.c					\
						$(SOURCES)$(NPC)npc.c                       \
						$(TESTS)


SRC_COUNT    =         $(words $(SRC))

NB           =         0

OBJ          =	        $(SRC:.c=.o)

TEMPFILES    =         *~ *vgcore* $(SRC:.c=.gcno) $(SRC:.c=.gcda) \
					   *.gcov

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
			"Tests files sucessfully build. "$(DEFAULT))
			@make -C ../lib/my/ --no-print-directory
			@make -C ../lib/myprintf/ --no-print-directory
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) -lcriterion --verbose --coverage\
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)
			@mv $(NAME) ..


clean:
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean Tests "$(DEFAULT))

fclean:		clean
			@$(RM) ../$(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean Tests "$(DEFAULT))

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && python3 ../build/build.py $< $(NB) \
			$(SRC_COUNT)

.PHONY: all re clean fclean debug