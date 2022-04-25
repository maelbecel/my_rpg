/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

TestSuite(Cinematiques, .timeout = 10);

Test(Cinematiques, Intro)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "RPG no seed",
                                                    sfFullscreen, NULL);
    cr_assert_eq(intro(window), EXIT_SUCCESS);
}

Test(Cinematiques, Outro)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "RPG no seed",
                                                    sfFullscreen, NULL);
    cr_assert_eq(outro(window), EXIT_SUCCESS);
}

Test(Cinematiques, Battle)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "RPG no seed",
                                                    sfFullscreen, NULL);
    sfSprite *a = sfSprite_create();
    sfSprite *b = sfSprite_create();
    cr_assert_eq(battle(window, a, b), EXIT_SUCCESS);
}
