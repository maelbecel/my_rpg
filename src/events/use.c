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
    {"apple", 20, 0, 0, 0},
    {"banana", 70, 0, 0, 0},
    {"biere", 500, 0, 0, 0},
    {"sword", 0, 6, 0, 0},
    {"shield", 0, 0, 0, 5},
    {"armor", 0, 0, 0, 10},
    {"baguette", 4, 0, 0, 0},
    {"beef", 200, 2, 0, 0},
    {"blob", 0, 0, 10, 0},
    {"blue_potion", 0, 0, 0, 7},
    {"boots", 0, 0, 0, 3},
    {"bow", 0, 5, 0, 0},
    {"carrot", 40, 0, 0, 0},
    {"chicken", 100, 0, 0, 2},
    {"crossbow", 0, 5, 0, 0},
    {"hache", 0, 6, 0, 0},
    {"potion", 300, 0, 0, 0},
    {"rouleau", 1, 1, 1, 1}
};

void use_item(game_t *game, item_t item)
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

int use(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    char *type = va_arg(arg, char *);
    if (game->scenes->page != BATTLE)
        return EXIT_FAILURE;
    if (!type)
        return EXIT_FAILURE;
    for (int i = 0; i < (int) (sizeof(item) / sizeof(item_t)); i++) {
        if (my_strcmp(type, item[i].type) == 0) {
            use_item(game, item[i]);
        }
    }
    return EXIT_SUCCESS;
}