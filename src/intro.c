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

static sfSprite *episprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("ressources/cinematiques/epitech.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){400, 300});
    sfSprite_setScale(sprite, (sfVector2f){0.3, 0.3});
    return sprite;
}

static sfRectangleShape *init_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    return rect;
}

int intro(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    int mul = -4;
    int opacity = 254;
    sfSprite *epitech = episprite();
    sfRectangleShape *rect = init_rect();
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/easports.ogg");

    sfMusic_play(music);
    while (opacity < 255) {
        time = sfClock_getElapsedTime(clock);
        if ((float)time.microseconds / MICRO >= 0.001) {
            sfClock_restart(clock);
            opacity += mul;
        }
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