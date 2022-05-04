/*
** EPITECH PROJECT, 2021
** displaynbr_hexa.c
** File description:
** display number in hexa base
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "formatstring.h"

char *fmy_putinhexa_capital(int nb)
{
    int quotient = nb;
    int r;
    char *base = "0123456789ABCDEF";
    char *res = malloc(16 * 10000);
    char *ret = malloc(16 * 10000);
    int j = 0;
    int x = 0;

    if (!res || !ret)
        return NULL;
    while (quotient != 0) {
        r = quotient % 16;
        res[j] = base[r];
        quotient /= 16;
        j++;
    }
    for (int i = j; i >= 0; i--)
        ret[x++] = res[i];
    free(res);
    return ret;
}

char *fdisplaynbr_hexa_capital(va_list argv)
{
    int nb = va_arg(argv, int);

    return fmy_putinhexa_capital(nb);
}

char *fdisplaynbr_hexa_capital_hashtag(va_list argv)
{
    int nb = va_arg(argv, int);

    return fus("0X", fmy_putinhexa_capital(nb));
}
