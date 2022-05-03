/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void htp_third(game_t *game, ...)
{
    game->scenes->page = HTP_3;
}

element_t **htp_third_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * (4 + 1));

    if (!elements)
        return NULL;
    elements[0] = init_element("assets/ui/button_1_full.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = init_element("assets/htp/stat.png", (sfVector2f){50, 600},
                        (sfVector2f){1920, 1080}, (sfVector2f){0.3, 0.3});
    elements[2] = init_element("assets/htp/quest.png", (sfVector2f){680, 600},
                        (sfVector2f){1920, 1080}, (sfVector2f){0.3, 0.3});
    elements[3] = init_element("assets/htp/inv_menu.png",
    (sfVector2f){1310, 600}, (sfVector2f){1920, 1080}, (sfVector2f){0.3, 0.3});
    elements[4] = NULL;
    return elements;
}

button_t **htp_third_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    if (!buttons)
        return NULL;
    buttons[0] = init_button("<-             ", BUTTON,
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    if (!buttons[0])
        return NULL;
    buttons[0]->action_clicked = htp_second;
    buttons[1] = init_button("MENU             ", BUTTON,
                        (sfVector2f){50, 250}, (sfVector2i){300, 100});
    if (!buttons[1])
        return NULL;
    buttons[1]->action_clicked = main_menu;
    buttons[2] = NULL;
    init_htp_buttons(buttons);
    return buttons;
}
