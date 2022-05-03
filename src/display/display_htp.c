/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int display_txt(game_t *game)
{
    if (draw_text("HOW TO PLAY : MENU PLAYER", game->settings->font,
                                    (sfVector3f){450, 100, 100}, game->window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (draw_text("Here is the menu of the player\nYou can upgrade the stats\n\
You can see the current quests and finally,\nThe inventory where you can \
delete items", game->settings->font, (sfVector3f){450, 250, 40}, game->window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int display_htp_third(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while (game->scenes[HTP_3].elements[e])
        draw_element(game->window, game->scenes[HTP_3].elements[e++]);
    while (game->scenes[HTP_3].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_3)) {
            draw_clicked(game->window, game->scenes[HTP_3].buttons[b++]);
            game->scenes[HTP_3].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_3))
            draw_hoover(game->window, game->scenes[HTP_3].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_3].buttons[b++]);
    }
    if (display_txt(game) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
