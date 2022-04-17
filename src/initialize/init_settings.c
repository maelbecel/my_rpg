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

element_t **settings_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0},
                        (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **settings_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    int i = 0;

    buttons[0] = init_button("MAIN MENU        ", "ressources/UI/button1.png",
                        (sfVector2f){700, 800}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("KEYS      ", "ressources/UI/button1.png",
                        (sfVector2f){700, 450}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = settings_key;
    buttons[2] = init_button("SOUNDS       ", "ressources/UI/button1.png",
                        (sfVector2f){700, 100}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = settings_sounds;
    buttons[3] = NULL;
    while (buttons[i]){
        buttons[i]->base->scale = (sfVector2f){0.6, 1};
        buttons[i]->clicked->scale = (sfVector2f){0.6, 1};
        buttons[i++]->hoover->scale = (sfVector2f){0.6, 1};
    }
    return buttons;
}
