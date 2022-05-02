/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int get_info_from_config(player_t *player, char *class)
{
    if ((player->hp = int_from_json(conc("config/",
                                    conc(class, ".json")), "health")) == -1)
        return EXIT_FAILURE;
    if ((player->strg = int_from_json(conc("config/",
                                conc(class, ".json")), "strength")) == -1)
        return EXIT_FAILURE;
    if ((player->spd = int_from_json(conc("config/",
                                        conc(class, ".json")), "speed")) == -1)
        return EXIT_FAILURE;
    if ((player->def = int_from_json(conc("config/",
                                    conc(class, ".json")), "defense")) == -1)
        return EXIT_FAILURE;
    if ((player->pt_stat = int_from_json(conc("config/",
                                conc(class, ".json")), "point_stat")) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

player_t *init_player(char *class)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->elem = NULL;
    if (!(player->timer = sfClock_create()))
        return NULL;
    player->save = malloc(sizeof(char) * 2);
    if (!player->save)
        return NULL;
    player->quest = NULL;
    player->save[1] = '\0';
    if (!(player->class = my_strdup(class)))
        return NULL;
    if (get_info_from_config(player, class) == EXIT_FAILURE)
        return NULL;
    if (!(player->inventory = init_inventory()))
        return NULL;
    player->stat = malloc(sizeof(battle_t));
    return player;
}
