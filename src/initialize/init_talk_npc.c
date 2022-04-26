/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t **npc_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * (3 + 1));

    elements[0] = init_element("assets/ui/button_1_full.png",
                    (sfVector2f){0, 0}, (sfVector2f){1920, 1080},
                    (sfVector2f){1, 1});
    elements[2] = init_element("assets/shop.png", (sfVector2f){50, 50},
                                (sfVector2f){119, 139}, (sfVector2f){3, 3.5});
    elements[3] = NULL;
    return elements;
}

button_t **npc_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (3 + 1));

    buttons[0] = init_button("", BUTTON, (sfVector2f){1050, 200},
                            (sfVector2i){796, 206});
    buttons[0]->base->scale = (sfVector2f){0.5, 0.7};
    buttons[1] = init_button("", BUTTON, (sfVector2f){1050, 350},
                            (sfVector2i){796, 206});
    buttons[1]->base->scale = (sfVector2f){0.5, 0.7};
    buttons[2] = init_button("", BUTTON, (sfVector2f){1050, 500},
                            (sfVector2i){796, 206});
    buttons[2]->base->scale = (sfVector2f){0.5, 0.7};
    buttons[3] = NULL;
    return buttons;
}
