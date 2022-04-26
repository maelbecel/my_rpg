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
    sfVector2f nb = va_arg(arg, sfVector2f);

    add_element_n(game, get, nb.x);
    delete_element_n(game, want, nb.y);
    va_end(arg);
}