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
    draw_text(conc("HP : ", inttochar(game->player->hp)), game->settings->font,
                                    (sfVector3f){100, 150, 40}, game->window);
    draw_text(conc("STRENGHT : ", inttochar(game->player->strg)),
            game->settings->font, (sfVector3f){100, 250, 40}, game->window);
    draw_text(conc("SPEED : ", inttochar(game->player->spd)),
            game->settings->font, (sfVector3f){100, 350, 40}, game->window);
    draw_text(conc("DEFENSE : ", inttochar(game->player->def)),
            game->settings->font, (sfVector3f){100, 450, 40}, game->window);
}

void display_inventory(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 3);
}

void draw_stat_char(game_t *game)
{
    draw_text(conc("HP : ", inttochar(game->player->hp)),
            game->settings->font, (sfVector3f){100, 200, 40}, game->window);
    draw_text(conc("STRENGHT : ", inttochar(game->player->strg)),
            game->settings->font, (sfVector3f){100, 300, 40}, game->window);
    draw_text(conc("SPEED : ", inttochar(game->player->spd)),
            game->settings->font, (sfVector3f){100, 400, 40}, game->window);
    draw_text(conc("DEFENSE : ", inttochar(game->player->def)),
            game->settings->font, (sfVector3f){100, 500, 40}, game->window);
    draw_text(conc("POINT STAT : ", inttochar(game->player->pt_stat)),
            game->settings->font, (sfVector3f){100, 600, 40}, game->window);
}
