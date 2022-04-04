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
    game->scenes->page = SETTINGS_KEY;
}

element_t **settings_key_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0}, (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **settings_key_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 8);
    int i = 0;

    buttons[0] = init_button("<-             ", "ressources/UI/button1.png",
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = settings;
    buttons[1] = init_button("UP", "ressources/UI/button1.png",
                        (sfVector2f){100, 300}, (sfVector2i){300, 100});
    buttons[2] = init_button("DOWN", "ressources/UI/button1.png",
                        (sfVector2f){100, 500}, (sfVector2i){300, 100});
    buttons[3] = init_button("LEFT", "ressources/UI/button1.png",
                        (sfVector2f){100, 700}, (sfVector2i){300, 100});
    buttons[4] = init_button("RIGHT", "ressources/UI/button1.png",
                        (sfVector2f){1100, 300}, (sfVector2i){300, 100});
    buttons[5] = init_button("PAUSE", "ressources/UI/button1.png",
                        (sfVector2f){1100, 500}, (sfVector2i){300, 100});
    buttons[6] = init_button("MENU", "ressources/UI/button1.png",
                        (sfVector2f){1100, 700}, (sfVector2i){300, 100});
    buttons[7] = NULL;
    while (buttons[i]) {
        buttons[i]->base->scale = (sfVector2f){3, 2};
        buttons[i]->clicked->scale = (sfVector2f){3, 2};
        buttons[i++]->hoover->scale = (sfVector2f){3, 2};
    }
    return buttons;
}