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