/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int rpg(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event)) {
            if (analyse_event(window, event) == 0)
                return 0;
        }
        sfRenderWindow_clear(window, sfWhite);
        sfRenderWindow_display(window);
    }
    return 0;
}

int main (int ac, UNUSED char **argv)
{
    if (ac != 1)
        return 84;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    window = sfRenderWindow_create(mode, "RPG no seed", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    intro(window);
    if (rpg(window, &event) == 0)
        sfRenderWindow_destroy(window);
    return 0;
}
