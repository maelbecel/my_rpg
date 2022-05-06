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
    char *str = format("PRESS '%s' TO SKIP",
                    getkey(int_from_json(SETTINGS_FILE, "skip_key")));

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, epitech, NULL);
    sfRectangleShape_setFillColor(rect,
                                    sfColor_fromRGBA(0, 0, 0, opacity));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    draw_text_white(str, 60, (sfVector2f){50, 930}, window);
    sfRenderWindow_display(window);
    free(str);
}
