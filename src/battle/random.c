/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int my_random(void)
{
    char random[100];
    int fd = open("/dev/urandom", O_RDONLY);
    int res = 0;

    if (fd == -1)
        return -1;
    read(fd, random, 100);
    close(fd);
    for (int i = 0; i < 100; i++)
        res += random[i];
    return ABS(res);
}
