/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** find_item
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void delete_item(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    char *type = va_arg(arg, char *);
    delete_element(game, type);
}

inventory_t *find_item(game_t *game, button_t *button)
{
    sfVector2f pos = {button->pos.x + 225, button->pos.y - 150};

    for (int i = 0; game->player->inventory[i]->type != NULL; i++) {
        if (pos.x == game->player->inventory[i]->button->pos.x &&
            pos.y == game->player->inventory[i]->button->pos.y) {
            return game->player->inventory[i];
        }
    }
    return NULL;
}
