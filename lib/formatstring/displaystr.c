/*
** EPITECH PROJECT, 2021
** displaychar.c
** File description:
** display char
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "formatstring.h"

int my_strlen(char const *str);

char *fdisplaystr(va_list argv)
{
    char *str = va_arg(argv, char *);

    return str;
}
