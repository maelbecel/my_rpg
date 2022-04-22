/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function that draw dialogue box
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_dialogue_box(sfRenderWindow *window, char *str)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f) {0, 930});
    sfRectangleShape_setSize(rect, (sfVector2f) {1920, 150});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(255, 255, 255, 100));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    draw_text_white(str, 60, (sfVector2f) {15, 930}, window);
    sfRenderWindow_display(window);
}
