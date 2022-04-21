/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_menu_player(game_t *game, sfEvent *event)
{
    for (int i = 0; game->scenes[MENU_PLAYER].buttons[i]; i++) {
        sfTexture_destroy(game->scenes[MENU_PLAYER].buttons[i]->base->texture);
        game->scenes[MENU_PLAYER].buttons[i]->base->texture =
                sfTexture_createFromFile("ressources/ui/button1.png", NULL);
        sfSprite_setTexture(game->scenes[MENU_PLAYER].buttons[i]->base->sprite,
                    game->scenes[MENU_PLAYER].buttons[i]->base->texture, true);
    }
    game->scenes[MENU_PLAYER].buttons[
            game->scenes[MENU_PLAYER].tab->page]->base->texture =
            sfTexture_createFromFile("ressources/ui/button_menu.png", NULL);
    sfSprite_setTexture(game->scenes[MENU_PLAYER].buttons[
                            game->scenes[MENU_PLAYER].tab->page]->base->sprite,
                            game->scenes[MENU_PLAYER].buttons[game->scenes[
                            MENU_PLAYER].tab->page]->base->texture, true);
    display_tab(game, event);
}

void display_stat(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 1);
    for (int b = 0; game->scenes[MENU_PLAYER].tab[STAT].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click_menu(game, b, MENU_PLAYER, STAT)) {
            draw_clicked(game->window,
                            game->scenes[MENU_PLAYER].tab[STAT].buttons[b]);
            game->scenes[MENU_PLAYER].tab[STAT].buttons[b]->action_clicked(
                                                                game, b, STAT);
        } else if (is_hoover_menu(game, b, MENU_PLAYER, STAT))
            draw_hoover(game->window,
                            game->scenes[MENU_PLAYER].tab[STAT].buttons[b]);
        else
            draw_button(game->window,
                            game->scenes[MENU_PLAYER].tab[STAT].buttons[b]);
    }
    draw_stat_char(game);
}

void display_quest(game_t *game, sfEvent *event)
{
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 2);
    draw_text(get_quests(game), game->settings->font,
                                    (sfVector3f){350, 300, 80}, game->window);
}

void display_tab(game_t *game, sfEvent *event)
{
    switch (game->scenes[MENU_PLAYER].tab->page) {
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
