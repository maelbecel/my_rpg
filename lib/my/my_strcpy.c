/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
