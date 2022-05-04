/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int clicked_menu(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    int t = va_arg(arg, int);
    sfSprite_setTexture(
        game->scenes[game->scenes->page].tab[t].buttons[i]->clicked->sprite,
        sfTexture_createFromFile("assets/ui/button1_clicked.png", NULL),
                                        sfTrue);
    va_end(arg);
    return EXIT_SUCCESS;
}

int clicked(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);

    sfSprite_setTexture(
        game->scenes[game->scenes->page].buttons[i]->clicked->sprite,
        sfTexture_createFromFile("assets/ui/button1_clicked.png", NULL),
                                        sfTrue);
    va_end(arg);
    return EXIT_SUCCESS;
}

void hoover_menu(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    int t = va_arg(arg, int);
    int s = va_arg(arg, int);
    sfSprite_setTexture(
            game->scenes[s].tab[t].buttons[i]->hoover->sprite,
            sfTexture_createFromFile("assets/ui/button1_hoover.png", NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void hoover(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    sfSprite_setTexture(
            game->scenes[game->scenes->page].buttons[i]->hoover->sprite,
            sfTexture_createFromFile("assets/ui/button1_hoover.png", NULL),
                                        sfTrue);
    va_end(arg);
    return;
}
