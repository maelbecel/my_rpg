/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void add_hp(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->hp += 10;
        game->player->pt_stat -= 1;
    }
}

void add_strenght(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->strg += 1;
        game->player->pt_stat -= 1;
    }
}

void add_speed(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->spd += 1;
        game->player->pt_stat -= 1;
    }
}

void add_defense(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->def += 1;
        game->player->pt_stat -= 1;
    }
}

void reset(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));
    game->player->hp = my_getnbr(parser(file, "health"));
    game->player->strg = my_getnbr(parser(file, "strength"));
    game->player->spd = my_getnbr(parser(file, "speed"));
    game->player->def = my_getnbr(parser(file, "defense"));
    game->player->pt_stat = my_getnbr(parser(file, "point_stat"));
}
