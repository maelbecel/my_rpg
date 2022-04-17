/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static bool skip(sfRenderWindow *window)
{
    int key = my_getnbr(parser("config/settings.json", "skip_key"));
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return true;
    return false;
}

static void move(sfSprite *player, sfSprite *enemy, int i)
{
    sfSprite_setPosition(player, (sfVector2f){i, 500});
    sfSprite_setPosition(enemy, (sfVector2f){1920 - i - 100, 500});
}

static void init(sfSprite *player, sfSprite *enemy, sfSprite *background)
{
    sfSprite_setTexture(background,
        sfTexture_createFromFile("ressources/cinematiques/battle.png", NULL),
                                                                    sfTrue);
    sfSprite_setPosition(player, (sfVector2f){0, 500});
    sfSprite_setPosition(enemy, (sfVector2f){1820, 500});
}

static void draw(sfRenderWindow *window, sfSprite *background,
                                            sfSprite *player, sfSprite *enemy)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawSprite(window, player, NULL);
    sfRenderWindow_drawSprite(window, enemy, NULL);
    draw_text_white("PRESS 'S' TO SKIP", 60, (sfVector2f){1300, 930}, window);
    sfRenderWindow_display(window);
}

int battle(sfRenderWindow *window, sfSprite *a, sfSprite *b)
{
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/fight.ogg");
    sfSprite *player = sfSprite_copy(a);
    sfSprite *enemy = sfSprite_copy(b);
    sfSprite *background = sfSprite_create();
    int i = 0;

    init(player, enemy, background);
    while (!skip(window)) {
        if (i < 840)
            i += 15;
        else {
            fight_display(music, window);
            break;
        }
        move(player, enemy, i);
        draw(window, background, player, enemy);
    }
    sfMusic_destroy(music);
    return 0;
}
