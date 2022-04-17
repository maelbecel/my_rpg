/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_outro(sfRenderWindow *window, sfSprite *epitech,
                    sfRectangleShape *rect, int opacity)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, epitech, NULL);
    sfRectangleShape_setFillColor(rect,
                                    sfColor_fromRGBA(0, 0, 0, opacity));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    draw_text_white("PRESS 'S' TO SKIP", 60,
                                        (sfVector2f){1300, 930}, window);
    sfRenderWindow_display(window);
}
