/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void settings(game_t *game, ...)
{
    game->scenes->page = SETTINGS;
}

void settings_frame(game_t *game, ...)
{
    game->scenes->page = FRAME;
}

element_t **settings_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    return elements;
}

button_t **settings_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    int i = 0;

    buttons[0] = init_button("MAIN MENU        ", "assets/ui/button1.png",
                        (sfVector2f){700, 800}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("KEYS      ", "assets/ui/button1.png",
                        (sfVector2f){700, 550}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = settings_key;
    buttons[2] = init_button("SOUNDS       ", "assets/ui/button1.png",
                        (sfVector2f){700, 300}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = settings_sounds;
    buttons[3] = init_button("FRAME        ", "assets/ui/button1.png",
                        (sfVector2f){700, 50}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = settings_frame;
    buttons[4] = NULL;
    while (buttons[i]) {
        buttons[i]->base->scale = (sfVector2f){0.6, 1};
        buttons[i]->clicked->scale = (sfVector2f){0.6, 1};
        buttons[i++]->hoover->scale = (sfVector2f){0.6, 1};
    }
    return buttons;
}
