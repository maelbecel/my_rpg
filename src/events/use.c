/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** use
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static const item_t item[] = {
    {"apple", 50, 0, 0, 0},
    {"banana", 70, 0, 0, 0},
    {"sword", 0, 5, 0, 0},
    {"shield", 0, 0, 0, 5},
    {"biere", 500, 0, 0, 0}
};

void use_item(game_t* game, item_t item)
{
    if (game->player->stat->hp < game->player->total_hp)
        game->player->stat->hp += item.hp;
    if (game->player->stat->hp > game->player->total_hp)
        game->player->stat->hp = game->player->total_hp;
    game->player->stat->strg += item.strg;
    game->player->stat->def += item.def;
    game->player->stat->spd += item.spd;
    delete_element(game, item.type);
}

void use(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    char *type = va_arg(arg, char *);
    if (!type)
        return;
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(type, item[i].type) == 0) {
            use_item(game, item[i]);
        }
    }
}