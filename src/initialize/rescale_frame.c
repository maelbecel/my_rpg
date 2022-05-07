/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void rescale_frame(button_t **buttons)
{
    int i = 0;
    buttons[4]->action_clicked = particles;
    buttons[5] = NULL;
    while (i < 3) {
        buttons[i]->base->scale = (sfVector2f){0.4, 1};
        buttons[i]->clicked->scale = (sfVector2f){0.4, 1};
        buttons[i++]->hoover->scale = (sfVector2f){0.4, 1};
    }
}