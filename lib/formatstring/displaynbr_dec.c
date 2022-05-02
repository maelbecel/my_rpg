/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <stdio.h>
#include <stdarg.h>
#include "formatstring.h"

static char *fuschar(char *res, char c)
{
    char buf[2];

    buf[0] = c;
    buf[1] = '\0';
    return fus(res, buf);
}

static char *my_put_nbr(int nb)
{
    int i = 0;
    char *res = "";

    if (nb < 0) {
        res = fuschar(res, '-');
        nb = -nb;
    }
    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        res = fus(res, my_put_nbr(nb));
        res = fuschar(res, i + 48);
    } else
        res = fuschar(res, nb + 48);
    return res;
}

char *fmy_put_nbr_dec(int nb)
{
    int i = 0;
    char *res = "";

    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        res = fus(res, fmy_put_nbr_dec(nb));
        res = fuschar(res, i + 48);
    } else
        res = fuschar(res, nb + 48);
}

char *fdisplaynbr_dec(va_list argv)
{
    unsigned int nb = va_arg(argv, unsigned int);
    int i = 0;
    char *res = "";

    if (nb > 9) {
        i = nb % 10;
        nb /= 10;
        res = fus(res, fmy_put_nbr_dec(nb));
        res = fuschar(res, i + '0');
    } else
        res = fuschar(res, nb + '0');
    return res;
}
