/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int display_battle(sfSprite *player, sfSprite *enemy, game_t *game)
{
    draw_element(game->window, game->scenes[GAME].elements[7]);
    draw_element(game->window, game->scenes[GAME].elements[2]);
    return EXIT_SUCCESS;
}
