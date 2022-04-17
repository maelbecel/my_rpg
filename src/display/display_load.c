/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void draw_free(int b, game_t *game, char * file)
{
    if (b < 3 && my_strcmp(parser(file, "new"), "1") == 0)
        draw_text("FREE SPACE", game->settings->font,
        (sfVector3f){game->scenes[LOAD].buttons[b]->pos.x + 510,
        game->scenes[LOAD].buttons[b]->pos.y + 130, 30}, game->window);
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
        draw_free(b, game, file);
        b++;
    }
}

void update_load(game_t *game)
{
    switch (my_getnbr(game->player->save)) {
        case 1: game->scenes[LOAD].buttons[0]->action_clicked = load_1;
            break;
        case 2: game->scenes[LOAD].buttons[1]->action_clicked = load_2;
            break;
        case 3: game->scenes[LOAD].buttons[2]->action_clicked = load_3;
            break;
        default:
            break;
    }
}

static void draw_chars(game_t *game)
{
    draw_arbaletier_char(game->window, game->settings->font);
    draw_archere_char(game->window, game->settings->font);
    draw_chevalier_char(game->window, game->settings->font);
    draw_cuisiniere_char(game->window, game->settings->font);
    draw_mage_char(game->window, game->settings->font);
    draw_valkyrie_char(game->window, game->settings->font);
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
            update_load(game);
        } else if (is_hoover(game, b, CHOOSING))
            draw_hoover(game->window, game->scenes[CHOOSING].buttons[b]);
        else
            draw_button(game->window, game->scenes[CHOOSING].buttons[b]);
        b++;
    }
    while (game->scenes[CHOOSING].elements[e])
        draw_element(game->window, game->scenes[CHOOSING].elements[e++]);
    draw_chars(game);
}
