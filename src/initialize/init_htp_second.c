/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void htp_second(game_t *game, ...)
{
    game->scenes->page = HTP_2;
}

element_t **htp_second_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);

    if (!elements)
        return NULL;
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    if (!elements[0])
        return NULL;
    return elements;
}

button_t **htp_second_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    if (!buttons)
        return NULL;
    buttons[0] = init_button("<-             ", BUTTON,
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    if (!buttons[0])
        return NULL;
    buttons[0]->action_clicked = htp_first;
    buttons[1] = init_button("->             ", BUTTON,
                        (sfVector2f){50, 250}, (sfVector2i){300, 100});
    if (!buttons[1])
        return NULL;
    buttons[1]->action_clicked = htp_third;
    buttons[2] = NULL;
    init_htp_buttons(buttons);
    return buttons;
}
