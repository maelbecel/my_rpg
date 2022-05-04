/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** anim_sprite
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void move_rect(sfIntRect *rect, int offset, int maxvalue)
{
    if (rect->left + offset >= maxvalue)
        rect->left = 0;
    else
        rect->left += offset;
}

void anim_sprite(element_t *elem, clock_bg_t *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    if (clock->seconds > clock->sec) {
        move_rect(&elem->rect, clock->offset, clock->max);
        sfSprite_setTextureRect(elem->sprite, elem->rect);
        sfClock_restart(clock->clock);
    }
}
