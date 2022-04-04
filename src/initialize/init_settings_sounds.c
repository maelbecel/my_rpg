/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void settings_sounds(game_t *game, ...)
{
    game->scenes->page = SETTINGS_SOUNDS;
}

element_t **settings_sounds_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0}, (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **settings_sounds_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);

    buttons[0] = init_button("<-             ", "ressources/UI/button1.png",
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = settings;
    buttons[1] = NULL;
    return buttons;
}