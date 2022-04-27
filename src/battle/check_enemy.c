/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int check_enemy(game_t *game)
{
    int random = 0;

    if ((random = my_random()) == -1)
        return -1;
    if (random % 100 == 0)
        battle(game, game->scenes[GAME].elements[2]->sprite,
                                    game->scenes[GAME].npc[0]->elem->sprite);
    return EXIT_SUCCESS;
}
