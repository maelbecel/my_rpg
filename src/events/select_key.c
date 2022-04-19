/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int set_up(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed) {
            game->settings->key_up = event->key.code;
            update_file(SETTINGS_FILE , "up_key",
                                            inttochar(game->settings->key_up));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

void wait_up(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_up(game, event))
            return;
    }
}

int set_down(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed) {
            game->settings->key_down = event->key.code;
            update_file(SETTINGS_FILE , "down_key",
                                        inttochar(game->settings->key_down));
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

void wait_down(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_down(game, event))
            return;
    }
}
