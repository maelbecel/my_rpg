/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

#define MICRO 1000000

static sfSprite *episprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("ressources/cinematiques/epitech.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){400, 300});
    sfSprite_setScale(sprite, (sfVector2f){0.3, 0.3});
    return sprite;
}

static sfSprite *lettersprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("ressources/cinematiques/E_letter.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){550, 300});
    sfSprite_setScale(sprite, (sfVector2f){0.3, 0.3});
    return sprite;
}

static sfRectangleShape *init_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    return rect;
}

static int check_clock(int mul, sfClock *clock)
{
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    if ((float)time.microseconds / MICRO >= 0.001) {
        return mul;
    }
    return 0;
}

void draw_text_white(char *text, int size, sfVector2f pos, sfRenderWindow *window)
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
    int key = my_getnbr(parser("config/settings.json", "skip_key"));
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return true;
    return false;
}

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

static void draw(sfRenderWindow *window, sfSprite *epitech, sfSprite *letter, sfVector2f opmul)
{
    if (opmul.y >= 0) {
        draw_all(window,letter);
        sfRenderWindow_drawSprite(window, epitech, NULL);
        return;
    } if (opmul.x < 240){
        sfSprite_setPosition(letter, (sfVector2f){490, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 190){
        sfSprite_setPosition(letter, (sfVector2f){630, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 140){
        sfSprite_setPosition(letter, (sfVector2f){770, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 90){
        sfSprite_setPosition(letter, (sfVector2f){910, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x < 40){
        sfSprite_setPosition(letter, (sfVector2f){1050, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    } if (opmul.x <= 0){
        sfSprite_setPosition(letter, (sfVector2f){1190, 350});
        sfRenderWindow_drawSprite(window, letter, NULL);
    }
    sfRenderWindow_drawSprite(window, epitech, NULL);
}

int intro(sfRenderWindow *window)
{
    sfClock *clock = sfClock_create();
    int mul = -4;
    int opacity = 249;
    sfSprite *epitech = episprite();
    sfSprite *letter = lettersprite();
    sfRectangleShape *rect = init_rect();
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/easports.ogg");

    sfMusic_play(music);
    while (opacity < 250 && !skip(window)) {
        opacity += check_clock(mul, clock);
        if (check_clock(mul, clock) != 0)
            sfClock_restart(clock);
        mul = (opacity <= 0) ? -mul : mul;
        sfRenderWindow_clear(window, sfBlack);
        draw(window, epitech, letter, (sfVector2f){opacity, mul});
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 0, 0, opacity));
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        draw_text_white("PRESS 'S' TO SKIP", 60, (sfVector2f){1300, 930}, window);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    return 0;
}