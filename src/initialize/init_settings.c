/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int settings(game_t *game, ...)
{
    game->scenes->page = SETTINGS;
    return EXIT_SUCCESS;
}

int settings_frame(game_t *game, ...)
{
    game->scenes->page = FRAME;
    return EXIT_SUCCESS;
}

element_t **settings_elements(void)
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

static void setscale(button_t **buttons)
{
    int i = 0;

    while (buttons[i]) {
        buttons[i]->base->scale = (sfVector2f){0.6, 1};
        buttons[i]->clicked->scale = (sfVector2f){0.6, 1};
        buttons[i++]->hoover->scale = (sfVector2f){0.6, 1};
    }
}

button_t **settings_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);

    if (!buttons)
        return NULL;
    buttons[0] = init_button("MAIN MENU        ", BUTTON,
                        (sfVector2f){700, 800}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("KEYS      ", BUTTON,
                        (sfVector2f){700, 550}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = settings_key;
    buttons[2] = init_button("SOUNDS       ", BUTTON,
                        (sfVector2f){700, 300}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = settings_sounds;
    buttons[3] = init_button("FRAME        ", BUTTON,
                        (sfVector2f){700, 50}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = settings_frame;
    buttons[4] = NULL;
    setscale(buttons);
    return buttons;
}
