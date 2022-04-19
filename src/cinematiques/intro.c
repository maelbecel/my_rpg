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
    if ((float)time.microseconds / MICRO >= 0.001) {
        return mul;
    }
    return 0;
}

void draw_text_white(char *text, int size, sfVector2f pos,
                                                        sfRenderWindow *window)
{
    sfText *score = sfText_create();
    sfText_setColor(score, sfWhite);
    sfText_setString(score, text);
    sfText_setFont(score, sfFont_createFromFile(BASIC_FONT));
    sfText_setCharacterSize(score, size);
    sfText_setPosition(score, pos);
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
}

static bool skip(sfRenderWindow *window)
{
    int key = my_getnbr(parser(SETTINGS_FILE , "skip_key"));
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return true;
    return false;
}

int intro(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    int mul = -4;
    int opacity = 249;
    sfSprite *epitech = episprite();
    sfSprite *letter = lettersprite();
    sfRectangleShape *rect = init_rect_rad();
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/easports.ogg");

    sfMusic_play(music);
    while (opacity < 250 && !skip(window)) {
        opacity += check_clock(mul, clock);
        if (check_clock(mul, clock) != 0)
            sfClock_restart(clock);
        mul = (opacity <= 0) ? -mul : mul;
        what_draw(window, epitech, letter, (sfVector2f){opacity, mul});
        draw_voil(window, rect, opacity);
    }
    sfMusic_destroy(music);
    return 0;
}
