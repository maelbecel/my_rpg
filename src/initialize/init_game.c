/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void play(game_t *game, ...)
{
    game->scenes->page = GAME;
}

element_t **game_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 9);

    if (!elements)
        return NULL;
    elements[0] = init_element("assets/village.jpg", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = init_element("assets/0-20.png",
        (sfVector2f){0, 0}, (sfVector2f){805, 1200}, (sfVector2f){0, 0});
    elements[2] = init_element(CROSSBOW_P, (sfVector2f){400, 120},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[3] = init_element("assets/village.jpg", (sfVector2f){1728, 0},
                        (sfVector2f){192, 108}, (sfVector2f){0.0, 0.0});
    elements[4] = init_element(CROSSBOW_P, (sfVector2f){1400, 0},
                        (sfVector2f){1920, 1080}, (sfVector2f){0.00, 0.0});
    elements[5] = init_element("assets/roof.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[6] = init_element("assets/shop_map.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[7] = NULL;
    return elements;
}

button_t **game_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 1);

    if (!buttons)
        return NULL;
    buttons[0] = NULL;
    return buttons;
}
