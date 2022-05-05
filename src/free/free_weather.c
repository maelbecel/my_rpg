/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void free_weather(game_t *game)
{
    free(game->weather->pix);
    sfTexture_destroy(game->weather->tex);
    sfSprite_destroy(game->weather->sprite);
}
