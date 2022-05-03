/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <unistd.h>
#include <stdarg.h>
#include "formatstring.h"

static char *fuschar(char *res, char c)
{
    char buf[2];

    buf[0] = c;
    buf[1] = '\0';
    return fus(res, buf);
}

char *fdisplaychar(va_list argv)
{
    int c = va_arg(argv, int);
    return fuschar("", c);
}
