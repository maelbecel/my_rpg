/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my printf
*/

#include "formatstring.h"
#include <stdarg.h>
#include <stdlib.h>

static const struct fflags Functions[] = {
    {&fdisplaychar, 'c'},
    {&fdisplaypercent, '%'},
    {&fdisplaynbr, 'i'},
    {&fdisplaynbr, 'd'},
    {&fdisplaynbr, 'h'},
    {&fdisplaynbr_long, 'l'},
    {&fdisplaystr, 's'},
    {&fdisplaybinary, 'b'},
    {&fdisplaystr_unprintable, 'S'},
    {&fdisplaynbr_octal, 'o'},
    {&fdisplaynbr_dec, 'u'},
    {&fdisplaynbr_hexa, 'x'},
    {&fdisplaynbr_hexa_capital, 'X'},
    {&fdisplaypointer, 'p'},
    {NULL, -1},
};

static const struct fflags Hashtags[] = {
    {&fdisplaynbr_octal_hashtag, 'o'},
    {&fdisplaynbr_hexa_hashtag, 'x'},
    {&fdisplaynbr_hexa_capital_hashtag, 'X'},
    {NULL, -1},
};

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *fus(char *a, char *b)
{
    char *res = malloc(my_strlen(a) + my_strlen(b) + 1);
    int x = 0;

    if (!res)
        return NULL;
    for (int i = 0; i < my_strlen(a); i++, x++)
        res[x] = a[i];
    for (int i = 0; i < my_strlen(b); i++, x++)
        res[x] = b[i];
    res[x] = '\0';
    return res;
}

char *fdisplayhashtag(char c, va_list argv)
{
    for (int i = 0; Hashtags[i].flag != -1; i++) {
        if (Hashtags[i].flag == c) {
            return Hashtags[i].func(argv);
        }
    }
    return NULL;
}

char *fdisplayflags(char c, va_list argv)
{
    for (int i = 0; Functions[i].flag != -1; i++) {
        if (Functions[i].flag == c) {
            return Functions[i].func(argv);
        }
    }
    return NULL;
}

char *format(char const *str, ...)
{
    va_list argv;
    va_start(argv, str);
    int i = -1;
    char *res = malloc(2);
    char buf[] = "\0\0";
    char *tmp;

    res[0] = '\0';
    while (str[++i] != '\0') {
        if (str[i] == '%') {
            tmp = fus(res, fdisplayflags(str[++i], argv));
        } else {
            buf[0] = str[i];
            tmp = fus(res, buf);
        }
        free(res);
        res = tmp;
    }
    va_end(argv);
    return tmp;
}
