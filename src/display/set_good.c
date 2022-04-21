/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void set_good(game_t *game, ...)
{
    game->scenes[GAME].elements[0]->rect.left = 0;
    game->scenes[GAME].elements[2]->pos.x = 900;
    game->scenes[GAME].elements[0]->rect.top = 0;
    game->scenes[GAME].elements[2]->pos.y = 500;
}
