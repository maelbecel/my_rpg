/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int check_clock(int mul, sfClock *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    if ((float)time.microseconds / MICRO >= 0.001)
        return mul;
    return 0;
}

static void destroy(sfClock *clock, sfSprite *epitech,
                                    sfRectangleShape *rect, sfSprite *letter)
{
    sfClock_destroy(clock);
    sfSprite_destroy(epitech);
    sfSprite_destroy(letter);
    sfRectangleShape_destroy(rect);
}

int intro(sfRenderWindow *window, int mul, int opacity)
{
    sfClock *clock = sfClock_create();
    sfSprite *epitech = episprite();
    sfSprite *letter = lettersprite();
    sfRectangleShape *rect = init_rect_rad();
    sfMusic *music = sfMusic_createFromFile("assets/sounds/easports.ogg");

    if (!clock || !epitech || !letter || !rect || !music)
        return EXIT_FAILURE;
    sfMusic_play(music);
    while (opacity < 250 && !skip(window)) {
        opacity += check_clock(mul, clock);
        if (check_clock(mul, clock) != 0)
            sfClock_restart(clock);
        mul = (opacity <= 0) ? -mul : mul;
        what_draw(window, epitech, letter, (sfVector2f){opacity, mul});
        draw_voil(window, rect, opacity);
    }
    destroy(clock, epitech, rect, letter);
    sfMusic_destroy(music);
    return EXIT_SUCCESS;
}
