/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void settings_key(game_t *game, ...)
{
    game->scenes->page = KEY;
}

element_t **settings_key_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);

    if (!elements)
        return NULL;
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    return elements;
}

static void init_key_buttons(button_t **buttons)
{
    buttons[0] = init_button("<-             ", BUTTON,
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = settings;
    buttons[1] = init_button("UP", BUTTON,
                        (sfVector2f){100, 300}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = wait_up;
    buttons[2] = init_button("DOWN", BUTTON,
                        (sfVector2f){100, 500}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = wait_down;
    buttons[3] = init_button("LEFT", BUTTON,
                        (sfVector2f){100, 700}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = wait_left;
    buttons[4] = init_button("RIGHT", BUTTON,
                        (sfVector2f){1100, 300}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = wait_right;
    buttons[5] = init_button("PAUSE", BUTTON,
                        (sfVector2f){1100, 500}, (sfVector2i){300, 100});
    buttons[5]->action_clicked = wait_pause;
    buttons[6] = init_button("MENU", BUTTON,
                        (sfVector2f){1100, 700}, (sfVector2i){300, 100});
}

button_t **settings_key_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 8);

    if (!buttons)
        return NULL;
    init_key_buttons(buttons);
    buttons[6]->action_clicked = wait_menu;
    buttons[7] = NULL;
    buttons[0]->base->scale = (sfVector2f){0.4, 1};
    buttons[0]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[0]->hoover->scale = (sfVector2f){0.4, 1};
    return buttons;
}
