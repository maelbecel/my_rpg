/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** trade
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void trade(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    char *get = va_arg(arg, char *);
    char *want = va_arg(arg, char *);
    int get_nb = va_arg(arg, int);
    int want_nb = va_arg(arg, int);

    add_element_n(game, get, get_nb);
    delete_element_n(game, want, want_nb);
    va_end(arg);
}