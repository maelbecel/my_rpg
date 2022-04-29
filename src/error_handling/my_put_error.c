/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my swap
*/

#include <unistd.h>
#include "my.h"

int my_put_error(char const *str)
{
    write(2, str, my_strlen(str));
    return 1;
}
