/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void popup(sfFont *font, char *str)
{
    sfVideoMode mode = {600, 200, 32};
    element_t *element = init_element("assets/ui/popup.png",
                                    (sfVector2f){0, 0}, (sfVector2f){600, 200},
                                    (sfVector2f){1, 1});
    sfRenderWindow *pop = sfRenderWindow_create(mode, "Warning !",
                                                        sfClose, NULL);
    sfRenderWindow_setPosition(pop, (sfVector2i){660 , 440});
    sfEvent event;

    while (sfRenderWindow_isOpen(pop)) {
        while (sfRenderWindow_pollEvent(pop, &event));
        if (event.type == sfEvtClosed )
            sfRenderWindow_close(pop);
        sfRenderWindow_clear(pop, sfWhite);
        draw_element(pop, element);
        draw_text(str, font, (sfVector3f){20, 50, 30}, pop);
        sfRenderWindow_display(pop);
    }
    free(str);
    sfRenderWindow_destroy(pop);
}
