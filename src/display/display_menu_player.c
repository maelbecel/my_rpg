/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_stat(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER)) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER))
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
    draw_text(conc("HP : ", inttochar(game->player->hp)), 40, (sfVector2f){100, 150}, game->window);
    draw_text(conc("STRENGHT : ", inttochar(game->player->strg)), 40, (sfVector2f){100, 250}, game->window);
    draw_text(conc("SPEED : ", inttochar(game->player->spd)), 40, (sfVector2f){100, 350}, game->window);
    draw_text(conc("DEFENSE : ", inttochar(game->player->def)), 40, (sfVector2f){100, 450}, game->window);
}

void display_inventory(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER)) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER))
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
    return;
}

void display_menu_player(game_t *game, sfEvent *event)
{
    switch(game->scenes[MENU_PLAYER].tab->page) {
        case 0: display_stat(game, event);
            break;
        case 1: display_inventory(game, event);
            break;
    }
}
