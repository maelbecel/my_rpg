/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_htp_second
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int display_txt(game_t *game)
{
    if (draw_text("HOW TO PLAY : BATTLE", game->settings->font,
                    (sfVector3f){450, 100, 100}, game->window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (draw_text("Here is the battle scene\nYou can basically attack the \
enemy or escape\nYou can also use the inventory to temporarily\nincrease your \
stat", game->settings->font, (sfVector3f){450, 250, 40},
                                                game->window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int display_htp_second(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while (game->scenes[HTP_2].elements[e])
        draw_element(game->window, game->scenes[HTP_2].elements[e++]);
    while (game->scenes[HTP_2].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, HTP_2)) {
            draw_clicked(game->window, game->scenes[HTP_2].buttons[b++]);
            game->scenes[HTP_2].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, HTP_2))
            draw_hoover(game->window, game->scenes[HTP_2].buttons[b++]);
        else
            draw_button(game->window, game->scenes[HTP_2].buttons[b++]);
    }
    if (display_txt(game) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}