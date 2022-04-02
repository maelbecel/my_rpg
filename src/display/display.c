/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_main_menu(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while(game->scenes[0].elements[e])
        draw_element(game->window, game->scenes[0].elements[e++]);
    while(game->scenes[0].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, 0)) {
            draw_clicked(game->window, game->scenes[0].buttons[b++]);
            game->scenes[0].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, 0))
            draw_hoover(game->window, game->scenes[0].buttons[b++]);
        else
            draw_button(game->window, game->scenes[0].buttons[b++]);
    }
}

void display_game(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    analyse_game(game, event);
    while(game->scenes[1].elements[e])
        draw_element(game->window, game->scenes[1].elements[e++]);
    while(game->scenes[1].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, 1)) {
            draw_clicked(game->window, game->scenes[1].buttons[b++]);
            game->scenes[1].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, 1))
            draw_hoover(game->window, game->scenes[1].buttons[b++]);
        else
            draw_button(game->window, game->scenes[1].buttons[b++]);
    }
}

void display(game_t *game, sfEvent *event)
{
    switch(game->scenes->page) {
        case 0: display_main_menu(game, event);
            break;
        case 1: display_game(game, event);
            break;
    }
}