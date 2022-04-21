/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_inventory
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t) * (SIZE_INVENTORY));

    for (int i = 0; i < SIZE_INVENTORY + 1; i++) {
        inventory[i].type = NULL;
        inventory[i].value = 0;
        inventory[i].elem = init_element("ressources/ui/button1.png",
        (sfVector2f){0, 0}, (sfVector2f){792, 206}, (sfVector2f){0.25, 0.8});
    }
    return inventory;
}