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

static bool skip(sfRenderWindow *window)
{
    int key = int_from_json(SETTINGS_FILE , "skip_key");
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return true;
    return false;
}

static void my_sleep(int time, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfTime time_s = sfClock_getElapsedTime(clock);

    while (time_s.microseconds / MICRO < time && !skip(window))
        time_s = sfClock_getElapsedTime(clock);
    sfClock_destroy(clock);
}

int lore(sfRenderWindow *window)
{
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
        if (draw_text_white(tmp, 60, (sfVector2f){50, 500},
                                            window) == EXIT_FAILURE)
            return EXIT_FAILURE;
        i++;
        sfRenderWindow_display(window);
    }
    my_sleep(3, window);
    return EXIT_SUCCESS;
}
