/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int set_act(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
            already_def(game, event->key.code)) {
            popup(game->settings->font, "\n\t\t\t\t\tKey already used");
            return EXIT_SUCCESS;
        } if (event->type == sfEvtKeyPressed) {
            game->settings->key_action = event->key.code;
            update_file(SETTINGS_FILE , "action_key",
                                        inttochar(game->settings->key_action));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int wait_action(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_act(game, event))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int set_skip(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
            already_def(game, event->key.code)) {
            popup(game->settings->font, "\n\t\t\t\t\tKey already used");
            return EXIT_SUCCESS;
        } if (event->type == sfEvtKeyPressed) {
            game->settings->key_skip = event->key.code;
            update_file(SETTINGS_FILE , "skip_key",
                                        inttochar(game->settings->key_skip));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int wait_skip(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_skip(game, event))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
