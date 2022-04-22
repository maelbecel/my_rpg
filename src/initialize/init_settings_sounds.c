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
    game->scenes->page = SOUNDS;
}

element_t **settings_sounds_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 6);
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = init_element("assets/ui/button1.png",
        (sfVector2f){600, 400}, (sfVector2f){823, 201}, (sfVector2f){1, 0.3});
    elements[2] = init_element("assets/ui/button1.png",
        (sfVector2f){600, 800}, (sfVector2f){823, 201}, (sfVector2f){1, 0.3});
    elements[3] = init_element("assets/ui/button1_hoover.png",
    (sfVector2f){600, 380}, (sfVector2f){823, 201}, (sfVector2f){0.1, 0.5});
    elements[4] = init_element("assets/ui/button1_hoover.png",
    (sfVector2f){600, 780}, (sfVector2f){823, 201}, (sfVector2f){0.1, 0.5});
    elements[5] = NULL;
    return elements;
}

button_t **settings_sounds_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);

    buttons[0] = init_button("<-             ", "assets/ui/button1.png",
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[0]->base->scale = (sfVector2f){0.4, 1};
    buttons[0]->clicked->scale = (sfVector2f){0.4, 1};
    buttons[0]->hoover->scale = (sfVector2f){0.4, 1};
    buttons[0]->action_clicked = settings;
    buttons[1] = NULL;
    return buttons;
}
