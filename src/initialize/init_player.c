/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

player_t *init_player(char *class)
{
    player_t *player = malloc(sizeof(player_t));

    player->elem = NULL;
    player->class = class;
    player->hp = my_getnbr(parser(conc("config/", conc(class, ".json")), "hp"));
    player->strg = my_getnbr(parser(conc("config/", conc(class, ".json")), "strg"));
    player->spd = my_getnbr(parser(conc("config/", conc(class, ".json")), "spd"));
    player->def = my_getnbr(parser(conc("config/", conc(class, ".json")), "def"));
    return player;
}