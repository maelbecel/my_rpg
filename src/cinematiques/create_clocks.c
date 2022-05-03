/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

clock_bg_t *create_clock(float sec, int offset, int max)
{
    clock_bg_t *clock = malloc(sizeof(clock_bg_t));
    clock->clock = sfClock_create();
    clock->seconds = 0;
    clock->sec = sec;
    clock->offset = offset;
    clock->max = max;
    return clock;
}
