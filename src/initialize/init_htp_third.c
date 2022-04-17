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
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0},
                        (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **htp_third_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    buttons[0] = init_button("<-             ", "ressources/UI/button1.png",
                        (sfVector2f){50,50}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = htp_second;
    buttons[1] = init_button("MENU             ", "ressources/UI/button1.png",
                        (sfVector2f){50, 250}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = main_menu;
    buttons[2] = NULL;
    buttons[0]->base->scale = (sfVector2f){0.4, 1};
    buttons[0]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[0]->hoover->scale = (sfVector2f){0.4, 1};
    buttons[1]->base->scale = (sfVector2f){0.4, 1};
    buttons[1]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[1]->hoover->scale = (sfVector2f){0.4, 1};
    return buttons;
}
