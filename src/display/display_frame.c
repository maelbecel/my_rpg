/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void draw_frame_buttons(game_t *game, sfEvent *event)
{
    int b = 0;
    int e = 0;

    while (game->scenes[FRAME].elements[e])
        draw_element(game->window, game->scenes[FRAME].elements[e++]);
    while (game->scenes[FRAME].buttons[b]) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, FRAME)) {
            draw_clicked(game->window, game->scenes[FRAME].buttons[b++]);
            game->scenes[FRAME].buttons[b - 1]->action_clicked(game, b - 1);
        } else if (is_hoover(game, b, FRAME))
            draw_hoover(game->window, game->scenes[FRAME].buttons[b++]);
        else
            draw_button(game->window, game->scenes[FRAME].buttons[b++]);
    }
}

int display_frame(game_t *game, sfEvent *event)
{
    char *value = inttochar(int_from_json(CONFIG_FILE, "framerate"));

    draw_frame_buttons(game, event);
    if (draw_text(value, game->settings->font, (sfVector3f){900, 450, 80},
        game->window) == EXIT_FAILURE) {
        free(value);
        return EXIT_FAILURE;
    } if (draw_text((int_from_json(CONFIG_FILE, "show_fps")) ? "ON" : "OFF",
            game->settings->font, (sfVector3f){1000, 705, 60},
                                            game->window) == EXIT_FAILURE) {
        free(value);
        return EXIT_FAILURE;
    } if (draw_text(!(int_from_json(CONFIG_FILE, "weather_speed")) ? "OFF" :
                    "ON", game->settings->font, (sfVector3f){1100, 915, 60},
                                            game->window) == EXIT_FAILURE) {
        free(value);
        return EXIT_FAILURE;
        }
    free(value);
    return EXIT_SUCCESS;
}
