/*
** EPITECH PROJECT, 2021
** displaybinary.c
** File description:
** display binary
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "formatstring.h"

static char *fuschar(char *res, char c)
{
    char buf[2];

    buf[0] = c;
    buf[1] = '\0';
    return fus(res, buf);
}

char *fdisplaybinary(va_list argv)
{
    int nb = va_arg(argv, int);
    char *res = malloc(sizeof(char) * nb);
    char *ret = malloc(sizeof(char) * nb);
    int i = 0;
    int r = nb;
    int x = 0;

    if (!res || !ret)
        return NULL;
    if (nb < 0)
        ret[x++] = '-';
    while (r > 0) {
        res[i] = r % 2 + '0';
        r = r / 2;
        i++;
    }
    for (i -= 1; i >= 0; ret[x++] = res[i], i--);
    ret[x] = '\0';
    free(res);
    return ret;
}
