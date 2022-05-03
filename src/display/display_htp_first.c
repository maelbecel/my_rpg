/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_htp_first
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void display_txt(game_t *game)
{
    draw_text("HOW TO PLAY : SETTINGS", game->settings->font,
                                    (sfVector3f){450, 100, 100}, game->window);
    draw_text("You can personalize a lot of things like the framerate,\n\
the sound or even change the keys", game->settings->font,
        (sfVector3f){450, 300, 40}, game->window);
}

void display_htp_first(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while (game->scenes[HTP_1].elements[e])
        draw_element(game->window, game->scenes[HTP_1].elements[e++]);
    while (game->scenes[HTP_1].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_1)) {
            draw_clicked(game->window, game->scenes[HTP_1].buttons[b++]);
            game->scenes[HTP_1].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_1))
            draw_hoover(game->window, game->scenes[HTP_1].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_1].buttons[b++]);
    }
    display_txt(game);
}