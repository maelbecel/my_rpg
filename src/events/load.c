/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void new_game(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    i++;
    game->player->save[0] = i + '0';
    game->scenes->page = CHOOSING;
    va_end(arg);
}

void load_1(game_t *game, ...)
{
    game->player->save[0] = '1';
    reset(game);
    game->scenes->page = GAME;
}

void load_2(game_t *game, ...)
{
    game->player->save[0] = '2';
    reset(game);
    game->scenes->page = GAME;
}

void load_3(game_t *game, ...)
{
    game->player->save[0] = '3';
    reset(game);
    game->scenes->page = GAME;
}

void load(game_t *game, ...)
{
    game->scenes->page = LOAD;
}
