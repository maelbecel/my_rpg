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
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0}, (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **htp_second_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    buttons[0] = init_button("<-             ", "ressources/UI/button1.png",
                        (sfVector2f){50,650}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = htp_first;
    buttons[1] = init_button("->             ", "ressources/UI/button1.png",
                        (sfVector2f){50, 850}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = htp_third;
    buttons[2] = NULL;
    buttons[0]->base->scale = (sfVector2f){0.4, 1};
    buttons[0]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[0]->hoover->scale = (sfVector2f){0.4, 1};
    buttons[1]->base->scale = (sfVector2f){0.4, 1};
    buttons[1]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[1]->hoover->scale = (sfVector2f){0.4, 1};
    return buttons;
}