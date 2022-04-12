/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_player(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER) && b != 0) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER) && b != 0)
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
            is_click(game, b, MENU_PLAYER) && b != 3) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER) && b != 3)
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
}

void display_stat(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER) && b != 1) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER) && b != 1)
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
}

void display_quest(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER) && b != 2) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER) && b != 2)
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
    draw_text("NO QUEST ACTUALLY", 80, (sfVector2f){400, 600}, game->window);
}

void display_menu_player(game_t *game, sfEvent *event)
{
    for (int i = 0; game->scenes[MENU_PLAYER].buttons[i]; i++){
        sfTexture_destroy(game->scenes[MENU_PLAYER].buttons[i]->base->texture);
        game->scenes[MENU_PLAYER].buttons[i]->base->texture = sfTexture_createFromFile("ressources/UI/button1.png", NULL);
        sfSprite_setTexture(game->scenes[MENU_PLAYER].buttons[i]->base->sprite, game->scenes[MENU_PLAYER].buttons[i]->base->texture, true);
    }
    game->scenes[MENU_PLAYER].buttons[game->scenes[MENU_PLAYER].tab->page]->base->texture = sfTexture_createFromFile("ressources/UI/button_menu.png", NULL);
    sfSprite_setTexture(game->scenes[MENU_PLAYER].buttons[game->scenes[MENU_PLAYER].tab->page]->base->sprite, game->scenes[MENU_PLAYER].buttons[game->scenes[MENU_PLAYER].tab->page]->base->texture, true);
    switch(game->scenes[MENU_PLAYER].tab->page) {
        case 0: display_player(game, event);
            break;
        case 1: display_stat(game, event);
            break;
        case 2: display_quest(game, event);
            break;
        case 3: display_inventory(game, event);
            break;
    }
}
