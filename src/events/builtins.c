/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void clicked(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    sfSprite_setTexture(game->scenes[game->scenes->page].buttons[i]->clicked->sprite,
            sfTexture_createFromFile("ressources/UI/button1_clicked.png",NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void hoover(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    sfSprite_setTexture(game->scenes[game->scenes->page].buttons[i]->hoover->sprite,
            sfTexture_createFromFile("ressources/UI/button1_hoover.png",NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void do_none(game_t *game, ...)
{
    (void)(game);
}

void quit(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    outro(game->window);
    sfRenderWindow_close(game->window);
    va_end(arg);
}