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

    scenes->elements = malloc(sizeof(element_t *) * (5 + 1));
    scenes->elements[0] = init_element("assets/lore/Sky.png",
        (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    scenes->elements[1] = init_element("assets/lore/DownLayer.png",
        (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    scenes->elements[2] = init_element("assets/lore/MiddleLayer.png",
        (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    scenes->elements[3] = init_element("assets/lore/TopLayer.png",
        (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    scenes->elements[4] = init_element("assets/lore/Light.png",
        (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    scenes->elements[5] = NULL;
    for (int i = 0; i < 5; i++) {
        sfTexture_setRepeated(scenes->elements[i]->texture, sfTrue);
    }
    return scenes;
}

clock_bg_t *create_clock(float sec, int offset, int max)
{
    clock_bg_t *clock = malloc(sizeof(clock_bg_t));
    clock->clock = sfClock_create();
    clock->seconds = 0;
    clock->sec = sec;
    clock->offset = offset;
    clock->max = max;
    return clock;
}

clock_bg_t **init_clock(void)
{
    clock_bg_t **clock = malloc(sizeof(clock_bg_t *) * (5 + 1));
    clock[0] = create_clock(0, 0, 1920);
    clock[1] = create_clock(0.0003, 2, 1920);
    clock[2] = create_clock(0.0003, 4, 1920);
    clock[3] = create_clock(0.0001, 7, 1920);
    clock[4] = create_clock(0.0001, 10, 1920);
    clock[5] = NULL;
    return clock;
}

int draw_lore(sfRenderWindow* window, scene_t* scenes, char *tmp, clock_bg_t **clock)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; scenes->elements[i] != NULL; i++) {
        anim_sprite(scenes->elements[i], clock[i]);
        draw_element(window, scenes->elements[i]);
    }
    if (draw_text_white(tmp, 60, (sfVector2f){50, 500},
                                        window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    sfRenderWindow_display(window);
    return EXIT_SUCCESS;
}

int lore(sfRenderWindow *window)
{
    scene_t *scenes = init_lore();
    clock_bg_t **clock_bg = init_clock();
    sfClock *clock = sfClock_create();
    char *buffer = "You need to find your seed \n(je developpe demain je \nsuis trop fatigue wesh)";
    sfTime time;
    char *tmp = "";

    if (!buffer)
        return EXIT_FAILURE;
    time = sfClock_getElapsedTime(clock);

    for (int i = 0; buffer[i] != '\0'; ) {
        time = sfClock_getElapsedTime(clock);
        if ((float) time.microseconds / MICRO < 0.1)
            continue;
        time = sfClock_restart(clock);
        tmp = format("%s%c", tmp, buffer[i]);
        i++;
        if (draw_lore(window, scenes, tmp, clock_bg))
            return EXIT_FAILURE;
        if (skip(window))
            return EXIT_SUCCESS;
    }
    my_sleep(3, window);
    return EXIT_SUCCESS;
}
