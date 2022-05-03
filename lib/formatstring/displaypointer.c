/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "formatstring.h"

char *fmy_putadress(long long nb)
{
    long long quotient = nb;
    long long r;
    char *base = "0123456789abcdef";
    char *res = malloc(16 * 10000);
    char *ret = malloc(16 * 10000);
    int j = 0;
    int x = 0;

    if (!res || !ret)
        return NULL;
    while (quotient != 0) {
        r = quotient % 16;
        res[j++] = base[r];
        quotient /= 16;
    }
    for (int i = j; i >= 0; ret[x++] = res[i], i--);
    ret[x] = '\0';
    free(res);
    return ret;
}

char *fdisplaypointer(va_list argv)
{
    long long nb = va_arg(argv, long long);
    char *res = "0x";

    return fus(res, fmy_putadress(nb));
}
