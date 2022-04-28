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
    char random[1];
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return -1;
    read(fd, random, 1);
    close(fd);
    return random[0];
}
