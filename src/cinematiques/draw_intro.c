/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void draw_all(sfRenderWindow *window, sfSprite *letter)
{
        sfSprite_setPosition(letter, (sfVector2f){490, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
        sfSprite_setPosition(letter, (sfVector2f){630, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
        sfSprite_setPosition(letter, (sfVector2f){770, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
        sfSprite_setPosition(letter, (sfVector2f){910, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
        sfSprite_setPosition(letter, (sfVector2f){1050, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
        sfSprite_setPosition(letter, (sfVector2f){1190, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
}

static void draw(sfRenderWindow *window, sfSprite *epitech, sfSprite *letter,
                                                            sfVector2f opmul)
{
    if (opmul.x < 240) {
        sfSprite_setPosition(letter, (sfVector2f){490, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 190) {
        sfSprite_setPosition(letter, (sfVector2f){630, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 140) {
        sfSprite_setPosition(letter, (sfVector2f){770, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 90) {
        sfSprite_setPosition(letter, (sfVector2f){910, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 40) {
        sfSprite_setPosition(letter, (sfVector2f){1050, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    }
    sfRenderWindow_drawSprite(window, epitech, NULL);
}

void what_draw(sfRenderWindow *window, sfSprite *epitech,
                                            sfSprite *letter, sfVector2f opmul)
{
    sfRenderWindow_clear(window, sfBlack);
    if (opmul.y >= 0) {
        draw_all(window, letter);
        sfRenderWindow_drawSprite(window, epitech, NULL);
    } else
        draw(window, epitech, letter, opmul);
}

void draw_voil(sfRenderWindow *window, sfRectangleShape *rect, int op)
{
    char *str = format("PRESS '%s' TO SKIP",
                            getkey(int_from_json(SETTINGS_FILE, "skip_key")));

    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, op));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    draw_text_white(str, 60, (sfVector2f){50, 930}, window);
    sfRenderWindow_display(window);
    free(str);
}
