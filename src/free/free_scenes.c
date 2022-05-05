/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void free_tab(scene_t *tab)
{
    for (int i = 0; tab->buttons[i]; i++) {
        free_button(tab->buttons[i]);
    }
    for (int i = 0; tab->elements[i]; i++)
        free_elements(tab->elements[i]);
    free(tab->buttons);
    free(tab->elements);
    free(tab);
}

void free_scenes(game_t *game)
{
    int size = sizeof(enum scenes);

    for (int i = 0; i < size; i++) {
        for (int j = 0; game->scenes[i].elements[j]; j++)
            free_elements(game->scenes[i].elements[j]);
        free(game->scenes[i].elements);
        for (int k = 0; game->scenes[i].buttons[k]; k++)
            free_button(game->scenes[i].buttons[k]);
        free(game->scenes[i].buttons);
        if (game->scenes[i].tab)
            free_tab(game->scenes[i].tab);
    }
    free(game->scenes);
}
