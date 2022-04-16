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

int battle(sfRenderWindow *window, sfSprite *a, sfSprite *b)
{
    sfMusic *music = sfMusic_createFromFile("ressources/sounds/easports.ogg");
    sfSprite *player = sfSprite_copy(a);
    sfSprite *enemy = sfSprite_copy(b);
    sfSprite *background = sfSprite_create();
    int i = 0;

    sfSprite_setTexture(background, sfTexture_createFromFile("ressources/cinematiques/battle.png", NULL), sfTrue);
    sfSprite_setPosition(player, (sfVector2f){0, 500});
    sfSprite_setPosition(enemy, (sfVector2f){1820, 500});
    sfMusic_play(music);
    while (!skip(window)) {
        if (i < 860)
            i += 10;
        else {
            draw_text_white("FIGHT", 260, (sfVector2f){600, 450}, window);
            sfRenderWindow_display(window);
            sleep(2);
            break;
        }
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setPosition(player, (sfVector2f){i, 500});
        sfSprite_setPosition(enemy, (sfVector2f){1920 - i - 100, 500});
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_drawSprite(window, player, NULL);
        sfRenderWindow_drawSprite(window, enemy, NULL);
        draw_text_white("PRESS 'S' TO SKIP", 60, (sfVector2f){1300, 930}, window);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    return 0;
}