/*
** EPITECH PROJECT, 2021
** displaystr_unprintale
** File description:
** display str unprintable charactere
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "formatstring.h"

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *fdisplayoctal(int nb)
{
    int quotient = nb;
    int r;
    char *base = "01234567";
    char *res = malloc(20);
    char *ret = malloc(20);
    int j = 0;
    int x = 0;

    if (!res || !ret)
        return NULL;
    for (;quotient != 0; j++) {
        r = quotient % 8;
        res[j] = base[r];
        quotient /= 8;
    }
    for (; my_strlen(res) != 3; res[j] = '0', j++);
    for (int i = j; i >= 0; ret[x++] = res[i], i--);
    ret[x] = '\0';
    free(res);
    return ret;
}

char *fdisplaystr_unprintable(va_list argv)
{
    char *str = va_arg(argv, char *);
    char *res = "";
    char *buf = " \0";

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] < 32 || str[i] >= 127)
            res = fus(res, fus("\\", fdisplayoctal(str[i])));
        else {
            buf[0] = str[i];
            fus(res, buf);
        }
    }
    return res;
}
