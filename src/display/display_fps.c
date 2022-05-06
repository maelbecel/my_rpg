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

int draw_fps(sfTime frame, game_t *game)
{
    char *show;
    char *str = format("FPS : %i", get_fps(frame));

    if ((show = parser(CONFIG_FILE, "show_fps")) != NULL &&
            (game->scenes->page == GAME) &&
            my_getnbr(show) == 1)
        if (draw_text_white(str, 40, (sfVector2f){50, 50},
                                            game->window) == EXIT_FAILURE)
            return EXIT_FAILURE;
    free(str);
    return EXIT_SUCCESS;
}
