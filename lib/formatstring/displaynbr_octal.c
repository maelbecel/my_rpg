/*
** EPITECH PROJECT, 2021
** displaynbr_octal.c
** File description:
** display nbr in octal
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

int fmy_getinoctal(int nb)
{
    int quotient = nb;
    int r;
    int res = 0;
    int x = 1;
    int j = 0;

    if (nb < 0) {
        quotient = quotient * -1;
        j += 1;
    }
    while (quotient != 0) {
        r = quotient % 8;
        res += r * x;
        quotient /= 8;
        j++;
        x *= 10;
    }
    return res;
}

char *fdisplaynbr_octal(va_list argv)
{
    unsigned int nb = va_arg(argv, unsigned int);
    char *res = "";
    if (nb < 0)
        res = fus(res, "-");
    return fus(res, my_put_nbr(fmy_getinoctal(nb)));
}

char *fdisplaynbr_octal_hashtag(va_list argv)
{
    return fdisplaynbr_octal(argv);
}
