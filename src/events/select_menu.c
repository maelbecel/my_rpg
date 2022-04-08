/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int set_pause(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed) {
            game->settings->key_pause = event->key.code;
            update_file("config/settings.json", "pause_key", inttochar(game->settings->key_pause));
            return 0;
        }
    }
    return 1;
}

void wait_pause(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_pause(game, event))
            return;
    }
}

int set_menu(game_t *game, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(game->window, event)) {
        if (event->type == sfEvtKeyPressed) {
            game->settings->key_menu = event->key.code;
            update_file("config/settings.json", "menu_key", inttochar(game->settings->key_menu));
            return 0;
        }
    }
    return 1;
}

void wait_menu(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    UNUSED int i = va_arg(arg, int);
    sfEvent *event = va_arg(arg, sfEvent *);

    while (sfRenderWindow_isOpen(game->window)) {
        if (!set_menu(game, event))
            return;
    }
}