/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void get_info_from_config(player_t *player, char *class)
{
    player->hp = int_from_json(conc("config/",
                                            conc(class, ".json")), "health");
    player->strg = int_from_json(conc("config/",
                                        conc(class, ".json")), "strength");
    player->spd = int_from_json(conc("config/",
                                            conc(class, ".json")), "speed");
    player->def = int_from_json(conc("config/",
                                            conc(class, ".json")), "defense");
    player->pt_stat = int_from_json(conc("config/",
                                        conc(class, ".json")), "point_stat");
    player->total_hp = player->hp;
}

player_t *init_player(char *class)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->elem = NULL;
    player->timer = sfClock_create();
    player->save = malloc(sizeof(char) * 2);
    if (!player->save)
        return NULL;
    player->quest = NULL;
    player->save[1] = '\0';
    player->class = my_strdup(class);
    get_info_from_config(player, class);
    player->inventory = init_inventory();
    return player;
}
