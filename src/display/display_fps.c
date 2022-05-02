/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int get_fps(sfTime frame)
{
    float second = (float)frame.microseconds / (float)MICRO;
    return (int)(1 / second) + 1;
}

void draw_fps(sfTime frame, game_t *game)
{
    char *show;

    if ((show = parser(CONFIG_FILE, "show_fps")) != NULL &&
            (game->scenes->page == GAME || game->scenes->page == BATTLE) &&
            my_getnbr(show) == 1)
        draw_text_white(format("FPS : %i", get_fps(frame)), 40,
                                        (sfVector2f){50, 50}, game->window);
}
