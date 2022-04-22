/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static const struct display_s Menu_list[] = {
    {MAIN_MENU, display_main_menu},
    {GAME, display_game},
    {SETTINGS, display_settings},
    {KEY, display_settings_key},
    {SOUNDS, display_settings_sounds},
    {MENU_PLAYER, display_menu_player},
    {HTP_1, display_htp_first},
    {HTP_2, display_htp_second},
    {HTP_3, display_htp_third},
    {PAUSE, display_pause},
    {LOAD, display_load},
    {CHOOSING, display_choosing},
    {FRAME, display_frame},
    {-1, NULL}
};

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
            game->scenes[MAIN_MENU].buttons[b - 1]->action_clicked(game,
                                                                        b - 1);
        } else if (is_hoover(game, b, MAIN_MENU))
            draw_hoover(game->window, game->scenes[MAIN_MENU].buttons[b++]);
        else
            draw_button(game->window, game->scenes[MAIN_MENU].buttons[b++]);
    }
}

static void set_minimap(game_t *game)
{
    game->scenes[GAME].elements[4]->pos.x =
                            (game->scenes[GAME].elements[0]->rect.left +
                            game->scenes[GAME].elements[2]->pos.x) / 30 + 1420;
    game->scenes[GAME].elements[4]->pos.y =
                            (game->scenes[GAME].elements[0]->rect.top +
                            game->scenes[GAME].elements[2]->pos.y) / 30 - 17;
}

void display_game(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    check_save(game);
    analyse_game(game, event);
    set_minimap(game);
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

void display_pause(game_t *game, sfEvent *event)
{
    for (int game_e = 0; game->scenes[GAME].elements[game_e];)
        draw_element(game->window, game->scenes[GAME].elements[game_e++]);
    for (int game_b = 0; game->scenes[GAME].buttons[game_b];)
        draw_button(game->window, game->scenes[GAME].buttons[game_b++]);
    for (int e = 0; game->scenes[PAUSE].elements[e];)
        draw_element(game->window, game->scenes[PAUSE].elements[e++]);
    for (int b = 0; game->scenes[PAUSE].buttons[b];) {
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
    sfRenderWindow_clear(game->window, sfWhite);
    for (int i = 0; Menu_list[i].scene != -1; i++) {
        if (Menu_list[i].scene == game->scenes->page) {
            Menu_list[i].func(game, event);
            return;
        }
    }
}
