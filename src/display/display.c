/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_main_menu(sfRenderWindow *window, scene_t *scenes, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while(scenes[0].elements[e])
        draw_element(window, scenes[0].elements[e++]);
    while(scenes[0].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(window, scenes, b, 0)) {
            draw_clicked(window, scenes[0].buttons[b++]);
            scenes[0].buttons[b - 1]->action_clicked(scenes, b - 1, window);
        } else if (is_hoover(window, scenes, b, 0))
            draw_hoover(window, scenes[0].buttons[b++]);
        else
            draw_button(window, scenes[0].buttons[b++]);
    }
}

void display(game_t *game, sfEvent *event)
{
    display_main_menu(game->window, game->scenes, event);
}