/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_settings(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while(game->scenes[SETTINGS].elements[e])
        draw_element(game->window, game->scenes[SETTINGS].elements[e++]);
    while(game->scenes[SETTINGS].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, SETTINGS)) {
            draw_clicked(game->window, game->scenes[SETTINGS].buttons[b++]);
            game->scenes[SETTINGS].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, SETTINGS))
            draw_hoover(game->window, game->scenes[SETTINGS].buttons[b++]);
        else
            draw_button(game->window, game->scenes[SETTINGS].buttons[b++]);
    }
}

void display_settings_key(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    concat_settings(game);
    while(game->scenes[KEY].elements[e])
        draw_element(game->window, game->scenes[KEY].elements[e++]);
    while(game->scenes[KEY].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, KEY)) {
            draw_clicked(game->window, game->scenes[KEY].buttons[b++]);
            game->scenes[KEY].buttons[b - 1]->action_clicked(game,
                                                                b - 1, event);
        } else if (is_hoover(game, b, KEY))
            draw_hoover(game->window, game->scenes[KEY].buttons[b++]);
        else
            draw_button(game->window, game->scenes[KEY].buttons[b++]);
    }
}

void display_settings_sounds(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    set_slider_pos(game);
    move_slider(game, event);
    set_slider_pos(game);
    while(game->scenes[SOUNDS].elements[e])
        draw_element(game->window, game->scenes[SOUNDS].elements[e++]);
    while(game->scenes[SOUNDS].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, SOUNDS)) {
            draw_clicked(game->window, game->scenes[SOUNDS].buttons[b++]);
            game->scenes[SOUNDS].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, SOUNDS))
            draw_hoover(game->window, game->scenes[SOUNDS].buttons[b++]);
        else
            draw_button(game->window, game->scenes[SOUNDS].buttons[b++]);
    }
    draw_text("MUSIC", game->settings->font, (sfVector3f){300, 380, 70}, game->window);
    draw_text("FX", game->settings->font, (sfVector3f){400, 780, 70}, game->window);
    draw_text(inttochar(game->settings->music_volume), game->settings->font,
                        (sfVector3f){1500, 380, 80}, game->window);
    draw_text(inttochar(game->settings->fx_volume), game->settings->font,
                        (sfVector3f){1500, 780, 80}, game->window);
}