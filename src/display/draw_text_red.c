/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_text_red(char *text, sfFont *font,
                                    sfVector3f pos, sfRenderWindow *window)
{
    sfText *score = sfText_create();

    sfText_setColor(score, sfRed);
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, pos.z);
    sfText_setPosition(score, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
}

void draw_text_green(char *text, sfFont *font,
                                    sfVector3f pos, sfRenderWindow *window)
{
    sfText *score = sfText_create();

    sfText_setColor(score, sfColor_fromRGB(100, 200, 130));
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, pos.z);
    sfText_setPosition(score, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
}
