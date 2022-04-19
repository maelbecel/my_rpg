/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int set_left(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
            already_def(game, event->key.code)) {
            popup(game->settings->font, "\n\t\t\t\t\tKey already used");
            return EXIT_SUCCESS;
        } if (event->type == sfEvtKeyPressed) {
            game->settings->key_left = event->key.code;
            update_file(SETTINGS_FILE , "left_key",
                                        inttochar(game->settings->key_left));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

void wait_left(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_left(game, event))
            return;
    }
}

int set_right(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
            already_def(game, event->key.code)) {
            popup(game->settings->font, "\n\t\t\t\t\tKey already used");
            return EXIT_SUCCESS;
        } if (event->type == sfEvtKeyPressed) {
            game->settings->key_right = event->key.code;
            update_file(SETTINGS_FILE , "right_key",
                                        inttochar(game->settings->key_right));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

void wait_right(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_right(game, event))
            return;
    }
}
