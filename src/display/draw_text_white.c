/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int draw_text_white(char *text, int size, sfVector2f pos,
                                                        sfRenderWindow *window)
{
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile(BASIC_FONT);

    if (!score || !font)
        return EXIT_FAILURE;
    sfText_setColor(score, sfWhite);
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, size);
    sfText_setPosition(score, pos);
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
    return EXIT_SUCCESS;
}
