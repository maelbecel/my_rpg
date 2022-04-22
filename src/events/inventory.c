/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

inventory_t *find_inventory(inventory_t **inventory, char *type)
{
    int i = 0;

    for (; i < SIZE_INVENTORY && inventory[i]->type != NULL; i++) {
        if (my_strcmp(type, inventory[i]->type) == 0 &&
            inventory[i]->value < 64)
            return inventory[i];
    }
    if (i < 32)
        return inventory[i];
    else
        return NULL;
}

void add_elem(game_t *game, char *type)
{
    inventory_t *inventory = find_inventory(game->player->inventory, type);

    if (inventory != NULL) {
        inventory->type = my_strdup(type);
        inventory->value += 1;
        inventory->elem = init_element(conc("assets/icons/",
                    conc(type, ".png")), (sfVector2f){0, 0}, (sfVector2f){32, 32},
                    (sfVector2f){3, 3});
    }
}
