/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void check_save(game_t *game)
{
    char *file = format("saves/save%s.json", game->player->save);
    char *posx = parser(file, "posx");
    char *posy = parser(file, "posy");
    char *hp = parser(file, "health");
    char *strg = parser(file, "strength");
    char *speed = parser(file, "speed");
    char *defense = parser(file, "defense");
    char *pt_st = parser(file, "point_stat");

    if (posx == NULL || posy == NULL || hp == NULL || strg == NULL ||
        speed == NULL || defense == NULL || pt_st == NULL) {
        popup(game->settings->font , "\t\tError: Save file corrupted");
        quit(game);
    }
}
