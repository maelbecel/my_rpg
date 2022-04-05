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
    }
}