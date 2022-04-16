/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void popup(game_t *game, char *str)
{
    sfVideoMode mode = {600, 200, 32};
    // element_t *element = init_element()
    sfRenderWindow *pop = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfClose, NULL);
    sfRenderWindow_setPosition(pop, (sfVector2i){660 , 440});
    sfEvent event;
    while (sfRenderWindow_isOpen(pop)) {
        while (sfRenderWindow_pollEvent(pop, &event));
        if (event.type == sfEvtClosed )
            sfRenderWindow_close(pop);
        sfRenderWindow_clear(pop, sfWhite);
        // draw_element(pop, element);
        draw_text(str, game->settings->font, (sfVector3f){160, 60, 30}, pop);
        sfRenderWindow_display(pop);
    }
    sfRenderWindow_destroy(pop);
}