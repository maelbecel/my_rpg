/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void clicked(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    int i = va_arg(arg, int);
    sfSprite_setTexture(scenes[scenes->page].buttons[i]->clicked->sprite,
            sfTexture_createFromFile("ressources/UI/button1_clicked.png",NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void hoover(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    int i = va_arg(arg, int);
    sfSprite_setTexture(scenes[scenes->page].buttons[i]->hoover->sprite,
            sfTexture_createFromFile("ressources/UI/button1_hoover.png",NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void do_none(scene_t *scenes, ...)
{
    (void)(scenes);
}

void quit(scene_t *scenes, ...)
{
    va_list arg;
    va_start(arg, scenes);
    (void)(scenes);
    UNUSED int i = va_arg(arg, int);
    sfRenderWindow *window = va_arg(arg, sfRenderWindow *);
    sfRenderWindow_close(window);
    va_end(arg);
}