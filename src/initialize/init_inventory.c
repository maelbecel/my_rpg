/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_inventory
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

inventory_t **init_inventory(void)
{
    inventory_t **inventory = malloc(sizeof(inventory_t *) *
                                        (SIZE_INVENTORY + 1));

    for (int i = 0; i < SIZE_INVENTORY + 1; i++) {
        inventory[i] = malloc(sizeof(inventory_t));
        inventory[i]->type = NULL;
        inventory[i]->value = 0;
        inventory[i]->elem = NULL;
        inventory[i]->button = init_button("", "ressources/ui/button1.png",
            (sfVector2f){0, 0}, (sfVector2i){792, 206});
        inventory[i]->button->base->scale = (sfVector2f){0.25, 0.8};
        inventory[i]->button->hoover->scale = (sfVector2f){0.25, 0.8};
        inventory[i]->button->clicked->scale = (sfVector2f){0.25, 0.8};
    }
    return inventory;
}