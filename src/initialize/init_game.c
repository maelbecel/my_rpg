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
    game->scenes->page = 1;
}

element_t **game_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 3);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1.6, 1.35});
    elements[1] = init_element("ressources/perso.png", (sfVector2f){900, 500}, (sfVector2f){1920, 1080}, (sfVector2f){0.8, 0.8});
    elements[2] = NULL;
    elements[0]->rect = (sfIntRect){0, 0, 1920, 1080};
    return elements;
}

button_t **game_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 1);
    buttons[0] = NULL;
    return buttons;
}