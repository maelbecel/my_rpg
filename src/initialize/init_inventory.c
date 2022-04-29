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

    if (!inventory)
        return NULL;
    for (int i = 0; i < SIZE_INVENTORY + 1; i++) {
        inventory[i] = malloc(sizeof(inventory_t));
        if (!inventory[i])
            return NULL;
        inventory[i]->type = NULL;
        inventory[i]->value = 0;
        inventory[i]->elem = NULL;
        inventory[i]->button = init_button("", BUTTON,
                                (sfVector2f){0, 0}, (sfVector2i){792, 206});
        inventory[i]->button->base->scale = (sfVector2f){0.25, 0.8};
        inventory[i]->button->hoover->scale = (sfVector2f){0.25, 0.8};
        inventory[i]->button->clicked->scale = (sfVector2f){0.25, 0.8};
        inventory[i]->button->action_clicked = menu_inventory;
        inventory[i]->button->action_hoover = hoover_inventory;
    }
    return inventory;
}

button_t **button_inventory(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (2 + 1));

    buttons[0] = init_button("", BUTTON, (sfVector2f){0, 0},
                            (sfVector2i){792, 206});
    buttons[1] = init_button("", BUTTON, (sfVector2f){0, 0},
                            (sfVector2i){792, 206});
    for (int i = 0; i < 2; i++) {
        buttons[i]->action_hoover = hoover_menu;
        buttons[i]->base->scale = (sfVector2f){0.4, 0.6};
        buttons[i]->hoover->scale = (sfVector2f){0.4, 0.6};
        buttons[i]->clicked->scale = (sfVector2f){0.4, 0.6};
    }
    buttons[2] = NULL;
    return buttons;
}