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

static scene_t *init_lore(void)
{
    scene_t *scenes = malloc(sizeof(scene_t));

    scenes->elements = malloc(sizeof(element_t *) * (7 + 1));
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
    scenes->elements[5] = init_element("assets/npc/old_men.png",
            (sfVector2f){300, 600}, (sfVector2f){32, 48}, (sfVector2f){8, 8});
    scenes->elements[6] =  init_element(BUTTON, (sfVector2f){700, 300},
                                (sfVector2f){792, 206}, (sfVector2f){1, 2});
    scenes->elements[7] = NULL;
    return scenes;
}

static clock_bg_t **init_clock(void)
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

static int draw_lore(sfRenderWindow *window, scene_t *scenes,
                                                char *tmp, clock_bg_t **clock)
{
    sfFont *font = sfFont_createFromFile(BASIC_FONT);
    char *value = format("PRESS '%s' TO SKIP",
                    getkey(int_from_json(SETTINGS_FILE, "skip_key")));

    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; scenes->elements[i] != NULL; i++) {
        if (i < 5)
            anim_sprite(scenes->elements[i], clock[i]);
        draw_element(window, scenes->elements[i]);
    }
    if (draw_text(tmp, font, (sfVector3f){740, 370, 35},
                                        window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    draw_text_white(value, 60, (sfVector2f){50, 980}, window);
    sfRenderWindow_display(window);
    sfFont_destroy(font);
    free(value);
    return EXIT_SUCCESS;
}

static void update_scenes(scene_t *scenes)
{
    for (int i = 0; i < 5; i++)
        sfTexture_setRepeated(scenes->elements[i]->texture, sfTrue);
}

int lore(sfRenderWindow *window)
{
    scene_t *scenes = init_lore();
    clock_bg_t **clock_bg = init_clock();
    sfClock *clock = sfClock_create();
    char *buffer = LORE;
    sfTime time;
    char *tmp = "";

    update_scenes(scenes);
    for (int i = 0; buffer[i] != '\0' && !skip(window); ) {
        time = sfClock_getElapsedTime(clock);
        if ((float) time.microseconds / MICRO < 0.1)
            continue;
        time = sfClock_restart(clock);
        tmp = format("%s%c", tmp, buffer[i]);
        i++;
        if (draw_lore(window, scenes, tmp, clock_bg))
            return EXIT_FAILURE;
        free(tmp);
        tmp = "";
    }
    return EXIT_SUCCESS;
}
