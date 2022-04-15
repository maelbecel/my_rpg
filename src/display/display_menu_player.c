/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_button_menu_player(game_t *game, sfEvent *event, int nb)
{
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER) && b != nb) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER) && b != nb)
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
}

void display_player(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 0);
    draw_text(conc("HP : ", inttochar(game->player->hp)), game->settings->font, (sfVector3f){100, 150, 40}, game->window);
    draw_text(conc("STRENGHT : ", inttochar(game->player->strg)), game->settings->font, (sfVector3f){100, 250, 40}, game->window);
    draw_text(conc("SPEED : ", inttochar(game->player->spd)), game->settings->font, (sfVector3f){100, 350, 40}, game->window);
    draw_text(conc("DEFENSE : ", inttochar(game->player->def)), game->settings->font, (sfVector3f){100, 450, 40}, game->window);
}

void display_inventory(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 3);
}

void display_stat(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 1);
    for (int b = 0; game->scenes[MENU_PLAYER].tab[STAT].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click_menu(game, b, MENU_PLAYER, STAT)) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].tab[STAT].buttons[b]);
            game->scenes[MENU_PLAYER].tab[STAT].buttons[b]->action_clicked(game, b, STAT);
        } else if (is_hoover_menu(game, b, MENU_PLAYER, STAT))
            draw_hoover(game->window, game->scenes[MENU_PLAYER].tab[STAT].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].tab[STAT].buttons[b]);
    }
    draw_text(conc("HP : ", inttochar(game->player->hp)), game->settings->font, (sfVector3f){100, 150, 40}, game->window);
    draw_text(conc("STRENGHT : ", inttochar(game->player->strg)), game->settings->font, (sfVector3f){100, 250, 40}, game->window);
    draw_text(conc("SPEED : ", inttochar(game->player->spd)), game->settings->font, (sfVector3f){100, 350, 40}, game->window);
    draw_text(conc("DEFENSE : ", inttochar(game->player->def)), game->settings->font, (sfVector3f){100, 450, 40}, game->window);
    draw_text(conc("POINT STAT : ", inttochar(game->player->pt_stat)), game->settings->font, (sfVector3f){100, 550, 40}, game->window);
}

void display_quest(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 2);
    draw_text("NO QUEST ACTUALLY", game->settings->font, (sfVector3f){400, 600, 80}, game->window);
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
