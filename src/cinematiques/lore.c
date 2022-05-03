/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

scene_t *init_lore(void)
{
    scene_t *scenes = malloc(sizeof(scene_t));

    scenes->elements = malloc(sizeof(element_t *) * (1 + 1));
    scenes->elements[0] = init_element("assets/lore/Sky.png",
        (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    scenes->elements[1] = NULL;
    return scenes;
}

int lore(sfRenderWindow *window)
{
    scene_t *scenes = init_lore();
    sfClock *clock = sfClock_create();
    char *buffer = "You need to find your seed \n(je developpe demain je \nsuis trop fatigue wesh)";
    sfTime time;
    char *tmp = "";
    size_t i = 0;

    if (!buffer)
        return EXIT_FAILURE;
    time = sfClock_getElapsedTime(clock);

    while (buffer[i] != '\0') {
        time = sfClock_getElapsedTime(clock);
        if ((float) time.microseconds / MICRO < 0.1)
            continue;
        time = sfClock_restart(clock);
        tmp = format("%s%c", tmp, buffer[i]);
        sfRenderWindow_clear(window, sfBlack);
        draw_element(window, scenes->elements[0]);
        if (draw_text_white(tmp, 60, (sfVector2f){50, 500},
                                            window) == EXIT_FAILURE)
            return EXIT_FAILURE;
        i++;
        sfRenderWindow_display(window);
        if (skip(window))
            return EXIT_SUCCESS;
    }
    my_sleep(3, window);
    return EXIT_SUCCESS;
}
