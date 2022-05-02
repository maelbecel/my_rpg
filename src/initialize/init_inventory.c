/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_inventory
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int create_slot(inventory_t **inventory, size_t i)
{
    inventory[i]->type = NULL;
    inventory[i]->value = 0;
    inventory[i]->elem = NULL;
    if (!(inventory[i]->button = init_button("", BUTTON,
                            (sfVector2f){0, 0}, (sfVector2i){792, 206})))
        return EXIT_FAILURE;
    inventory[i]->button->base->scale = (sfVector2f){0.25, 0.8};
    inventory[i]->button->hoover->scale = (sfVector2f){0.25, 0.8};
    inventory[i]->button->clicked->scale = (sfVector2f){0.25, 0.8};
    inventory[i]->button->action_clicked = menu_inventory;
    inventory[i]->button->action_hoover = hoover_inventory;
    return EXIT_SUCCESS;
}

inventory_t **init_inventory(void)
{
    inventory_t **inventory = malloc(sizeof(inventory_t *) *
                                        (SIZE_INVENTORY + 1));

    if (!inventory)
        return NULL;
    for (size_t i = 0; i < SIZE_INVENTORY + 1; i++) {
        inventory[i] = malloc(sizeof(inventory_t));
        if (!inventory[i])
            return NULL;
        create_slot(inventory, i);
    }
    return inventory;
}

button_t **button_inventory(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (2 + 1));

    buttons[0] = init_button("Use", BUTTON, (sfVector2f){0, 0},
                            (sfVector2i){792, 206});
    buttons[0]->action_clicked = use;
    buttons[1] = init_button("Delete", BUTTON, (sfVector2f){0, 0},
                            (sfVector2i){792, 206});
    buttons[1]->action_clicked = delete_item;
    for (int i = 0; i < 2; i++) {
        buttons[i]->action_hoover = hoover_menu;
        buttons[i]->base->scale = (sfVector2f){0.4, 0.6};
        buttons[i]->hoover->scale = (sfVector2f){0.4, 0.6};
        buttons[i]->clicked->scale = (sfVector2f){0.4, 0.6};
        buttons[i]->base->text_pos.x = 50;
        buttons[i]->base->text_pos.y = 30;
        buttons[i]->hoover->text_pos.x = 50;
        buttons[i]->hoover->text_pos.y = 30;
        buttons[i]->clicked->text_pos.x = 50;
        buttons[i]->clicked->text_pos.y = 30;
    }
    buttons[2] = NULL;
    return buttons;
}