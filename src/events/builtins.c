/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int do_none(game_t *game, ...)
{
    (void)(game);
    return EXIT_SUCCESS;
}

int quit(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    outro(game->window);
    sfRenderWindow_close(game->window);
    va_end(arg);
    return EXIT_SUCCESS;
}
