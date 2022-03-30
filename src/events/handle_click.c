/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int is_hoover(sfRenderWindow *window, scene_t *scenes, int b, int s)
{
    sfVector2f pos = scenes[s].buttons[b]->pos;
    sfVector2f scale = scenes[s].buttons[b]->base->scale;
    sfVector2u size = sfTexture_getSize(scenes[s].buttons[b]->hoover->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(window);
    size.x *= scale.x;
    size.y *= scale.y;
    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            scenes[s].buttons[b]->action_hoover(scenes, b);
            return 1;
        }
    }
    return 0;
}

int is_click(sfRenderWindow *window, scene_t *scenes, int b, int s)
{
    if (!is_hoover(window, scenes, b, s) || !sfRenderWindow_isOpen(window))
        return 0;
    return 1;
}
