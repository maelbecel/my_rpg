/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void fight_display(sfMusic *music, sfRenderWindow *window)
{
    sfMusic_play(music);
    draw_text_white("FIGHT", 260, (sfVector2f){600, 450}, window);
    sfRenderWindow_display(window);
    sleep(2);
}
