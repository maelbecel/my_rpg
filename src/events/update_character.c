/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

const void *CLASS[6][2] = {
    {"chevalier", KNIGHT_P},
    {"valkyrie", VALKYRIE_P},
    {"mage", MAGE_P},
    {"archer", ARCHER_P},
    {"cooker", COOKER_P},
    {"arbeletier", CROSSBOW_P},
};

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
    char *class = clean_string(parser(file, "class"));

    game->player->hp = my_getnbr(parser(file, "health"));
    game->player->strg = my_getnbr(parser(file, "strength"));
    game->player->spd = my_getnbr(parser(file, "speed"));
    game->player->def = my_getnbr(parser(file, "defense"));
    game->player->pt_stat = my_getnbr(parser(file, "point_stat"));
    for(int i = 0; i < 6; i++) {
        if (my_strcmp(class, CLASS[i][0]) == 0) {
            sfTexture_destroy(game->scenes[GAME].elements[2]->texture);
            game->scenes[GAME].elements[2]->texture =
                                sfTexture_createFromFile(CLASS[i][1], NULL);
            sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
            return;
        }
    }
}
