/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void go_to_player(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 0;
}

void go_to_stat(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 1;
}

void go_to_quest(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 2;
}

void go_to_inventory(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 3;
}
