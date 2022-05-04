/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int main_menu(game_t *game, ...)
{
    game->scenes->page = MAIN_MENU;
    return EXIT_SUCCESS;
}

static void main_menu_actions(button_t **buttons)
{
    buttons[0]->action_clicked = load;
    buttons[1]->action_clicked = htp_first;
    buttons[2]->action_clicked = settings;
    buttons[3]->action_clicked = quit;
}

element_t **main_menu_elements(void)
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

button_t **main_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    sfVector2i size = (sfVector2i){300, 100};

    if (!buttons)
        return NULL;
    if (!(buttons[0] = init_button("PLAY", BUTTON, (sfVector2f){1200, 90},
                                                                        size)))
        return NULL;
    if (!(buttons[1] = init_button("HELP", BUTTON, (sfVector2f){1200, 300},
                                                                        size)))
        return NULL;
    if (!(buttons[2] = init_button("SETTINGS", BUTTON,
                                            (sfVector2f){1200, 510}, size)))
        return NULL;
    if (!(buttons[3] = init_button("QUIT", BUTTON, (sfVector2f){1200, 720},
                                                                        size)))
        return NULL;
    buttons[4] = NULL;
    main_menu_actions(buttons);
    return buttons;
}
