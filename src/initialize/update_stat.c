/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void update_stat(button_t **buttons)
{
    for (int i = 0; i < 4; i++) {
        buttons[i]->action_hoover = hoover_menu;
        buttons[i]->base->scale = (sfVector2f){0.5, 0.4};
        buttons[i]->clicked->scale = (sfVector2f){0.5, 0.4};
        buttons[i]->hoover->scale = (sfVector2f){0.5, 0.4};
        buttons[i]->base->text_pos.x *= 0.5;
        buttons[i]->base->text_pos.y *= 0.4;
        buttons[i]->clicked->text_pos.x *= 0.5;
        buttons[i]->clicked->text_pos.y *= 0.4;
        buttons[i]->hoover->text_pos.x *= 0.5;
        buttons[i]->hoover->text_pos.y *= 0.4;
    }
    buttons[5] = NULL;
}
