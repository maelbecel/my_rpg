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

    if (!elements)
        return NULL;
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    if (!elements[0])
        return NULL;
    return elements;
}

void init_htp_buttons(button_t **buttons)
{
    buttons[0]->base->scale = (sfVector2f){0.4, 1};
    buttons[0]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[0]->hoover->scale = (sfVector2f){0.4, 1};
    buttons[1]->base->scale = (sfVector2f){0.4, 1};
    buttons[1]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[1]->hoover->scale = (sfVector2f){0.4, 1};
}

button_t **htp_first_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    if (!buttons)
        return NULL;
    buttons[0] = init_button("<-             ", BUTTON,
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    if (!buttons[0])
        return NULL;
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("->             ", BUTTON,
                        (sfVector2f){50, 250}, (sfVector2i){300, 100});
    if (!(buttons[1]))
        return NULL;
    buttons[1]->action_clicked = htp_second;
    buttons[2] = NULL;
    init_htp_buttons(buttons);
    return buttons;
}

int init_htp(scene_t *scenes, sfRenderWindow *window)
{
    if (!(scenes[HTP_1].buttons = htp_first_buttons()))
        return EXIT_FAILURE;
    loading(17, window);
    if (!(scenes[HTP_1].elements = htp_first_elements()))
        return EXIT_FAILURE;
    loading(18, window);
    if (!(scenes[HTP_2].buttons = htp_second_buttons()))
        return EXIT_FAILURE;
    loading(19, window);
    if (!(scenes[HTP_2].elements = htp_second_elements()))
        return EXIT_FAILURE;
    loading(20, window);
    if (!(scenes[HTP_3].buttons = htp_third_buttons()))
        return EXIT_FAILURE;
    loading(21, window);
    if (!(scenes[HTP_3].elements = htp_third_elements()))
        return EXIT_FAILURE;
    loading(22, window);
    return EXIT_SUCCESS;
}
