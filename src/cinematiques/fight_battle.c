/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

bool skip(sfRenderWindow *window)
{
    int key = int_from_json(SETTINGS_FILE , "skip_key");
    sfEvent event;

    if (sfRenderWindow_pollEvent(window, &event) &&
        event.type == sfEvtKeyPressed && event.key.code == key)
        return true;
    return false;
}

void my_sleep(float time, sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    sfTime time_s = sfClock_getElapsedTime(clock);

    while (time_s.microseconds < time && !skip(window))
        time_s = sfClock_getElapsedTime(clock);
    sfClock_destroy(clock);
}

void fight_display(sfMusic *music, sfRenderWindow *window)
{
    sfMusic_play(music);
    draw_text_white("FIGHT", 260, (sfVector2f){600, 450}, window);
    sfRenderWindow_display(window);
    my_sleep(FIGHT_WAIT, window);
}
