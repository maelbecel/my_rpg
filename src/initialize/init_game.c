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
    element_t **elements = malloc(sizeof(element_t *) * 6);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1.5, 1.5});
    elements[1] = init_element("ressources/0-20.png",
        (sfVector2f){0, 0}, (sfVector2f){805, 1200}, (sfVector2f){1, 1});
    elements[2] = init_element("ressources/perso.png", (sfVector2f){900, 500},
                            (sfVector2f){1920, 1080}, (sfVector2f){0.8, 0.8});
    elements[3] = init_element("ressources/map.png", (sfVector2f){1420, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){0.05, 0.05});
    elements[4] = init_element("ressources/perso.png", (sfVector2f){1400, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){0.08, 0.08});
    elements[5] = NULL;
    elements[0]->rect = (sfIntRect){0, 0, 1920, 1080};
    elements[3]->rect = (sfIntRect){0, 0, 10000, 5275};
    return elements;
}

button_t **game_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 1);
    buttons[0] = NULL;
    return buttons;
}