/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static sfRectangleShape *init_rect(float number, sfVector2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, (sfVector2f){190 * (number / 100), 30});
    return rect;
}

static sfColor get_color(float percent)
{
    if (percent < 33)
        return sfColor_fromRGB(200, 10, 50);
    else if (percent < 66)
        return sfColor_fromRGB(200, 200, 0);
    else
        return sfColor_fromRGB(10, 200, 50);
}

void draw_life(int at, int on, game_t *game, sfVector2f pos)
{
    sfRectangleShape *rect = init_rect((float)(at) / (on) * 100, pos);
    element_t *element = init_element("assets/ui/load.png", pos,
                            (sfVector2f){960, 100}, (sfVector2f){0.2, 0.3});

    sfRectangleShape_setFillColor(rect, get_color((float)(at) / (on) * 100));
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    draw_element(game->window, element);
    free_elements(element);
    sfRectangleShape_destroy(rect);
}
