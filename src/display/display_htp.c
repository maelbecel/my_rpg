/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_htp_second(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while (game->scenes[HTP_2].elements[e])
        draw_element(game->window, game->scenes[HTP_2].elements[e++]);
    while (game->scenes[HTP_2].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_2)) {
            draw_clicked(game->window, game->scenes[HTP_2].buttons[b++]);
            game->scenes[HTP_2].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_2))
            draw_hoover(game->window, game->scenes[HTP_2].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_2].buttons[b++]);
    }
    draw_text("HOW TO PLAY PAGE 2", game->settings->font,
                                    (sfVector3f){400, 400, 40}, game->window);
}

void display_htp_third(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while (game->scenes[HTP_3].elements[e])
        draw_element(game->window, game->scenes[HTP_3].elements[e++]);
    while (game->scenes[HTP_3].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_3)) {
            draw_clicked(game->window, game->scenes[HTP_3].buttons[b++]);
            game->scenes[HTP_3].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_3))
            draw_hoover(game->window, game->scenes[HTP_3].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_3].buttons[b++]);
    }
    draw_text("HOW TO PLAY PAGE 3", game->settings->font,
                                    (sfVector3f){400, 400, 40}, game->window);
}
