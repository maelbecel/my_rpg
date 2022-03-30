/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

#define MICRO 1000000

static sfSprite *shreksprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("ressources/cinematiques/shrek.jpg", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){550, 300});
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    return sprite;
}

static sfRectangleShape *init_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    return rect;
}

static int check_clock(int mul, sfClock *clock)
{
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    if ((float)time.microseconds / MICRO >= 0.001) {
        return mul;
    }
    return 0;
}

int outro(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    int mul = -4;
    int opacity = 249;
    sfSprite *epitech = shreksprite();
    sfRectangleShape *rect = init_rect();
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/shrek.ogg");

    sfMusic_play(music);
    while (opacity < 250) {
        opacity += check_clock(mul, clock);
        if (check_clock(mul, clock) != 0)
            sfClock_restart(clock);
        mul = (opacity <= 0) ? -mul : mul;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, epitech, NULL);
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, opacity));
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    return 0;
}