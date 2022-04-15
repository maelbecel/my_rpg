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

    while (game->scenes[MAIN_MENU].elements[e])
        draw_element(game->window, game->scenes[MAIN_MENU].elements[e++]);
    while (game->scenes[MAIN_MENU].buttons[b]) {
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

void display_game(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    analyse_game(game, event);
    game->scenes[GAME].elements[4]->pos.x = (game->scenes[GAME].elements[0]->rect.left + game->scenes[GAME].elements[2]->pos.x) / 30 + 1420;
    game->scenes[GAME].elements[4]->pos.y = (game->scenes[GAME].elements[0]->rect.top + game->scenes[GAME].elements[2]->pos.y) / 30 - 17;
    while (game->scenes[GAME].elements[e])
        draw_element(game->window, game->scenes[GAME].elements[e++]);
    while (game->scenes[GAME].buttons[b]) {
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

void display_load(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;
    char *file;

    while (game->scenes[LOAD].elements[e])
        draw_element(game->window, game->scenes[LOAD].elements[e++]);
    while (game->scenes[LOAD].buttons[b]) {
        file = conc("saves/save", conc(inttochar(b + 1), ".json"));
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, LOAD)) {
            draw_clicked(game->window, game->scenes[LOAD].buttons[b]);
            game->scenes[LOAD].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, LOAD))
            draw_hoover(game->window, game->scenes[LOAD].buttons[b]);
        else
            draw_button(game->window, game->scenes[LOAD].buttons[b]);
        if (b < 3 && my_strcmp(parser(file, "new"), "1") == 0)
            draw_text("FREE SPACE", game->settings->font, (sfVector3f){game->scenes[LOAD].buttons[b]->pos.x + 510, game->scenes[LOAD].buttons[b]->pos.y + 130, 30}, game->window);
        b++;
    }
}

void display_choosing(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 1;

    draw_element(game->window, game->scenes[CHOOSING].elements[0]);
    while (game->scenes[CHOOSING].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, CHOOSING)) {
            draw_clicked(game->window, game->scenes[CHOOSING].buttons[b]);
            game->scenes[CHOOSING].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, CHOOSING))
            draw_hoover(game->window, game->scenes[CHOOSING].buttons[b]);
        else
            draw_button(game->window, game->scenes[CHOOSING].buttons[b]);
        b++;
    }
    while (game->scenes[CHOOSING].elements[e])
        draw_element(game->window, game->scenes[CHOOSING].elements[e++]);
    draw_arbaletier_char(game->window, game->settings->font);
    draw_archere_char(game->window, game->settings->font);
    draw_chevalier_char(game->window, game->settings->font);
    draw_cuisiniere_char(game->window, game->settings->font);
    draw_mage_char(game->window, game->settings->font);
    draw_valkyrie_char(game->window, game->settings->font);
}

void display_pause(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;
    int game_e = 0;
    int game_b = 0;

    while (game->scenes[GAME].elements[game_e])
        draw_element(game->window, game->scenes[GAME].elements[game_e++]);
    while (game->scenes[GAME].buttons[game_b]) {
        draw_button(game->window, game->scenes[GAME].buttons[game_b++]);
    }

    while (game->scenes[PAUSE].elements[e])
        draw_element(game->window, game->scenes[PAUSE].elements[e++]);
    while (game->scenes[PAUSE].buttons[b]) {
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

void display(game_t *game, sfEvent *event)
{
    switch (game->scenes->page) {
        case MAIN_MENU: display_main_menu(game, event);
            break;
        case GAME: display_game(game, event);
            break;
        case SETTINGS: display_settings(game, event);
            break;
        case KEY: display_settings_key(game, event);
            break;
        case SOUNDS: display_settings_sounds(game, event);
            break;
        case MENU_PLAYER: display_menu_player(game, event);
            break;
        case HTP_1: display_htp_first(game, event);
            break;
        case HTP_2: display_htp_second(game, event);
            break;
        case HTP_3: display_htp_third(game, event);
            break;
        case PAUSE: display_pause(game, event);
            break;
        case LOAD: display_load(game, event);
            break;
        case CHOOSING: display_choosing(game, event);
            break;
    }
}