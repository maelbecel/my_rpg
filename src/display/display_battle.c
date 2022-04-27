/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_battle(game_t *game, sfEvent *event)
{
    for (int i = 0; game->scenes[BATTLE].elements[i] != NULL; i++)
        draw_element(game->window, game->scenes[BATTLE].elements[i]);
    for (int i = 0; game->scenes[BATTLE].buttons[i] != NULL; i++){
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, i, BATTLE)) {
            draw_clicked(game->window, game->scenes[BATTLE].buttons[i]);
            game->scenes[BATTLE].buttons[i]->action_clicked(game);
        } else if (is_hoover(game, i, BATTLE))
            draw_hoover(game->window, game->scenes[BATTLE].buttons[i]);
        else
            draw_button(game->window, game->scenes[BATTLE].buttons[i]);
    }
    return;
}
