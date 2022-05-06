/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void fill_player(player_t *player, char *file)
{
    player->hp = int_from_json(file, "health");
    player->strg = int_from_json(file, "strength");
    player->def = int_from_json(file, "defense");
    player->spd = int_from_json(file, "speed");
    player->pt_stat = int_from_json(file, "points_stat");
}

static int get_info_from_config(player_t *player, char *class)
{
    char *file = format("config/%s.json", class);

    fill_player(player, file);
    if (player->hp == -1)
        return EXIT_FAILURE;
    if (player->strg == -1)
        return EXIT_FAILURE;
    if (player->spd == -1)
        return EXIT_FAILURE;
    if (player->def == -1)
        return EXIT_FAILURE;
    free(file);
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
