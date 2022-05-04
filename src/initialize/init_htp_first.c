/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int htp_first(game_t *game, ...)
{
    game->scenes->page = HTP_1;
    return EXIT_SUCCESS;
}

element_t **htp_first_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * (4 + 1));

    if (!elements)
        return NULL;
    elements[0] = init_element("assets/ui/button_1_full.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = init_element("assets/htp/frame.png", (sfVector2f){50, 600},
                        (sfVector2f){1920, 1080}, (sfVector2f){0.3, 0.3});
    elements[2] = init_element("assets/htp/sound.png", (sfVector2f){680, 600},
                        (sfVector2f){1920, 1080}, (sfVector2f){0.3, 0.3});
    elements[3] = init_element("assets/htp/key.png", (sfVector2f){1310, 600},
                        (sfVector2f){1920, 1080}, (sfVector2f){0.3, 0.3});
    elements[4] = NULL;
    if (!elements[0] || !elements[1] || !elements[2] || !elements[3])
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
