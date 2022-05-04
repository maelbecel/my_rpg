/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

bool already_def(game_t *game, int i)
{
    if (i == game->settings->key_down ||
        i == game->settings->key_up ||
        i == game->settings->key_left ||
        i == game->settings->key_right ||
        i == game->settings->key_pause ||
        i == game->settings->key_skip ||
        i == game->settings->key_action ||
        i == game->settings->key_menu)
        return true;
    return false;
}

int set_pause(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
            already_def(game, event->key.code)) {
            popup(game->settings->font, "\n\t\t\t\t\tKey already used");
            return EXIT_SUCCESS;
        } if (event->type == sfEvtKeyPressed) {
            game->settings->key_pause = event->key.code;
            update_file(SETTINGS_FILE , "pause_key",
                                        inttochar(game->settings->key_pause));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int wait_pause(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_pause(game, event))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int set_menu(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed &&
            already_def(game, event->key.code)) {
            popup(game->settings->font, "\n\t\t\t\t\tKey already used");
            return EXIT_SUCCESS;
        } if (event->type == sfEvtKeyPressed) {
            game->settings->key_menu = event->key.code;
            update_file(SETTINGS_FILE , "menu_key",
                                        inttochar(game->settings->key_menu));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

int wait_menu(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_menu(game, event))
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
