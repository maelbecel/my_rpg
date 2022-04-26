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
    element_t **elements = malloc(sizeof(element_t *) * (2 + 1));

    elements[1] = init_element("assets/ui/button1.png", (sfVector2f){600, 0},
                                (sfVector2f){793, 206}, (sfVector2f){3, 8});
    elements[2] = init_element("assets/shop.png", (sfVector2f){50, 50},
                                (sfVector2f){119, 139}, (sfVector2f){3, 3.5});
    elements[3] = NULL;
    return elements;
}

button_t **npc_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (1));

    buttons[0] = NULL;
    return buttons;
}
