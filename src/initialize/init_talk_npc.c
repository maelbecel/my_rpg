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
    element_t **elements = malloc(sizeof(element_t *) * (1));

    elements[1] = NULL;
    return elements;
}

button_t **npc_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (1));

    buttons[0] = NULL;
    return buttons;
}