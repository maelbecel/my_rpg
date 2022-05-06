/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static sfRectangleShape *init_rect(float number)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){480, 540});
    sfRectangleShape_setSize(rect, (sfVector2f){960 * (number / 100), 50});
    return rect;
}

void loading(int number, sfRenderWindow *window)
{
    sfRectangleShape *rect = init_rect((float)(number + 1) /
                                                            (NB_SCENES) * 100);
    sfRectangleShape *red = init_rect(100);
    char *str = format("%i%%", (int)((float)(number + 1) / (NB_SCENES) * 100));

    sfRenderWindow_clear(window, sfBlack);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(10, 200, 50));
    sfRectangleShape_setFillColor(red, sfColor_fromRGB(200, 10, 50));
    sfRenderWindow_drawRectangleShape(window, red, NULL);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    draw_text_white(str, 60, (sfVector2f){1450, 530}, window);
    draw_text_white("LOADING ...", 60, (sfVector2f){840, 460}, window);
    sfRenderWindow_display(window);
    sfRectangleShape_destroy(rect);
    sfRectangleShape_destroy(red);
    free(str);
}
