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

    while(game->scenes[MAIN_MENU].elements[e])
        draw_element(game->window, game->scenes[MAIN_MENU].elements[e++]);
    while(game->scenes[MAIN_MENU].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MAIN_MENU)) {
            draw_clicked(game->window, game->scenes[MAIN_MENU].buttons[b++]);
            game->scenes[MAIN_MENU].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, MAIN_MENU))
            draw_hoover(game->window, game->scenes[MAIN_MENU].buttons[b++]);
        else
            draw_button(game->window, game->scenes[MAIN_MENU].buttons[b++]);
    }
}

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
    while(game->scenes[SETTINGS_KEY].elements[e])
        draw_element(game->window, game->scenes[SETTINGS_KEY].elements[e++]);
    while(game->scenes[SETTINGS_KEY].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, SETTINGS_KEY)) {
            draw_clicked(game->window, game->scenes[SETTINGS_KEY].buttons[b++]);
            game->scenes[SETTINGS_KEY].buttons[b - 1]->action_clicked(game, b - 1, event);
        } else if (is_hoover(game, b, SETTINGS_KEY))
            draw_hoover(game->window, game->scenes[SETTINGS_KEY].buttons[b++]);
        else
            draw_button(game->window, game->scenes[SETTINGS_KEY].buttons[b++]);
    }
}

void display_settings_sounds(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    move_slider(game, event);
    set_slider_pos(game);
    while(game->scenes[SETTINGS_SOUNDS].elements[e])
        draw_element(game->window, game->scenes[SETTINGS_SOUNDS].elements[e++]);
    while(game->scenes[SETTINGS_SOUNDS].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, SETTINGS_SOUNDS)) {
            draw_clicked(game->window, game->scenes[SETTINGS_SOUNDS].buttons[b++]);
            game->scenes[SETTINGS_SOUNDS].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, SETTINGS_SOUNDS))
            draw_hoover(game->window, game->scenes[SETTINGS_SOUNDS].buttons[b++]);
        else
            draw_button(game->window, game->scenes[SETTINGS_SOUNDS].buttons[b++]);
    }
    draw_text("MUSIC", 70, (sfVector2f){300, 380}, game->window);
    draw_text("FX", 70, (sfVector2f){400, 780}, game->window);
    draw_text(inttochar(game->settings->music_volume), 80, (sfVector2f){1500, 380}, game->window);
    draw_text(inttochar(game->settings->fx_volume), 80, (sfVector2f){1500, 780}, game->window);
}

void display_game(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    analyse_game(game, event);
    while(game->scenes[GAME].elements[e])
        draw_element(game->window, game->scenes[GAME].elements[e++]);
    while(game->scenes[GAME].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, GAME)) {
            draw_clicked(game->window, game->scenes[GAME].buttons[b++]);
            game->scenes[GAME].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, GAME))
            draw_hoover(game->window, game->scenes[GAME].buttons[b++]);
        else
            draw_button(game->window, game->scenes[GAME].buttons[b++]);
    }
}

void display_pause(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;
    int game_e = 0;
    int game_b = 0;

    while(game->scenes[GAME].elements[game_e])
        draw_element(game->window, game->scenes[GAME].elements[game_e++]);
    while(game->scenes[GAME].buttons[game_b]) {
        draw_button(game->window, game->scenes[GAME].buttons[game_b++]);
    }

    while(game->scenes[PAUSE].elements[e])
        draw_element(game->window, game->scenes[PAUSE].elements[e++]);
    while(game->scenes[PAUSE].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, PAUSE)) {
            draw_clicked(game->window, game->scenes[PAUSE].buttons[b++]);
            game->scenes[PAUSE].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, PAUSE))
            draw_hoover(game->window, game->scenes[PAUSE].buttons[b++]);
        else
            draw_button(game->window, game->scenes[PAUSE].buttons[b++]);
    }
}

void display_htp_first(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while(game->scenes[HTP_1].elements[e])
        draw_element(game->window, game->scenes[HTP_1].elements[e++]);
    while(game->scenes[HTP_1].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_1)) {
            draw_clicked(game->window, game->scenes[HTP_1].buttons[b++]);
            game->scenes[HTP_1].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_1))
            draw_hoover(game->window, game->scenes[HTP_1].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_1].buttons[b++]);
    }
    draw_text("HOW TO PLAY PAGE 1", 40, (sfVector2f){400, 400}, game->window);
}

void display_htp_second(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while(game->scenes[HTP_2].elements[e])
        draw_element(game->window, game->scenes[HTP_2].elements[e++]);
    while(game->scenes[HTP_2].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_2)) {
            draw_clicked(game->window, game->scenes[HTP_2].buttons[b++]);
            game->scenes[HTP_2].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_2))
            draw_hoover(game->window, game->scenes[HTP_2].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_2].buttons[b++]);
    }
    draw_text("HOW TO PLAY PAGE 2", 40, (sfVector2f){400, 400}, game->window);
}

void display_htp_third(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while(game->scenes[HTP_3].elements[e])
        draw_element(game->window, game->scenes[HTP_3].elements[e++]);
    while(game->scenes[HTP_3].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_3)) {
            draw_clicked(game->window, game->scenes[HTP_3].buttons[b++]);
            game->scenes[HTP_3].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_3))
            draw_hoover(game->window, game->scenes[HTP_3].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_3].buttons[b++]);
    }
    draw_text("HOW TO PLAY PAGE 3", 40, (sfVector2f){400, 400}, game->window);
}

void display_menu_player(game_t *game)
{
    int e = 0;

    while(game->scenes[MENU_PLAYER].elements[e])
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e++]);
}

void display(game_t *game, sfEvent *event)
{
    switch(game->scenes->page) {
        case MAIN_MENU: display_main_menu(game, event);
            break;
        case GAME: display_game(game, event);
            break;
        case SETTINGS: display_settings(game, event);
            break;
        case SETTINGS_KEY: display_settings_key(game, event);
            break;
        case SETTINGS_SOUNDS: display_settings_sounds(game, event);
            break;
        case MENU_PLAYER: display_menu_player(game);
            break;
        case HTP_1: display_htp_first(game, event);
            break;
        case HTP_2: display_htp_second(game, event);
            break;
        case HTP_3: display_htp_third(game, event);
            break;
        case PAUSE: display_pause(game, event);
            break;
    }
}