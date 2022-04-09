/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void htp_first(game_t *game, ...)
{
    game->scenes->page = HTP_1;
}

element_t **htp_first_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0},
                        (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **htp_first_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    buttons[0] = init_button("<-             ", "ressources/UI/button1.png",
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("->             ", "ressources/UI/button1.png",
                        (sfVector2f){50, 250}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = htp_second;
    buttons[2] = NULL;
    buttons[0]->base->scale = (sfVector2f){0.4, 1};
    buttons[0]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[0]->hoover->scale = (sfVector2f){0.4, 1};
    buttons[1]->base->scale = (sfVector2f){0.4, 1};
    buttons[1]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[1]->hoover->scale = (sfVector2f){0.4, 1};
    return buttons;
}

void init_htp(scene_t *scenes)
{
    scenes[HTP_1].buttons = htp_first_buttons();
    scenes[HTP_1].elements = htp_first_elements();
    scenes[HTP_2].buttons = htp_second_buttons();
    scenes[HTP_2].elements = htp_second_elements();
    scenes[HTP_3].buttons = htp_third_buttons();
    scenes[HTP_3].elements = htp_third_elements();
}