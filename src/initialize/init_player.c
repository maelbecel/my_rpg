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

    player->elem = init_element("ressources/perso.png", (sfVector2f){900, 500},
                            (sfVector2f){1920, 1080}, (sfVector2f){0.8, 0.8});
    player->hp = my_getnbr(parser(concat("config/",class,".json"), "hp"));
    player->strg = my_getnbr(parser(concat("config/",class,".json"), "strg"));
    player->spd = my_getnbr(parser(concat("config/",class,".json"), "spd"));
    player->def = my_getnbr(parser(concat("config/",class,".json"), "def"));
    return player;
}