/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int menu_event(game_t *game)
{
    if (game->scenes->page == MENU_PLAYER)
        game->scenes->page = GAME;
    else
        game->scenes->page = MENU_PLAYER;
    return 0;
}

int event_menu_player(game_t *game, sfEvent *event)
{
    for (int b = 0; game->scenes[MENU_PLAYER].tab[STAT].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click_menu(game, b, MENU_PLAYER, STAT)) {
            game->scenes[MENU_PLAYER].tab[STAT].buttons[b]->action_clicked(game, b, STAT);
        }
    }
    return 0;
}