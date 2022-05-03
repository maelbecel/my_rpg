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

int lore(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfClock *clock_2 = sfClock_create();
    char *buffer = "You need to find your seed \n(je développe demain je \nsuis trop fatigué wesh";
    sfTime time;
    char *tmp = malloc(2);
    size_t i = 0;
    sfTime time_tmp;

    tmp[0] = '\0';
    if (!buffer)
        return EXIT_FAILURE;
    time = sfClock_getElapsedTime(clock);
            time_tmp = sfClock_getElapsedTime(clock_2);

    while ((float)time.microseconds / MICRO < 30) {
        if (buffer[i] == '\0')
            break;
        sfRenderWindow_clear(window, sfBlack);
        printf("%i\n", (int)(time_tmp.microseconds));
        time = sfClock_getElapsedTime(clock);
        time_tmp = sfClock_getElapsedTime(clock_2);
        if (((int)time_tmp.microseconds / MICRO) % 10) {
            tmp = format("%s%c", tmp, buffer[i]);
            if (draw_text_white(tmp, 60, (sfVector2f){50, 500},
                                                window) == EXIT_FAILURE)
                return EXIT_FAILURE;
            i++;
        }
        sfRenderWindow_display(window);
    }
    return EXIT_SUCCESS;
}
