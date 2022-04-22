/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

sfSprite *episprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("assets/cinematiques/epitech.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){400, 300});
    sfSprite_setScale(sprite, (sfVector2f){0.3, 0.3});
    return sprite;
}

sfSprite *lettersprite(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture =
        sfTexture_createFromFile("assets/cinematiques/E_letter.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, (sfVector2f){550, 300});
    sfSprite_setScale(sprite, (sfVector2f){0.3, 0.3});
    return sprite;
}

sfRectangleShape *init_rect_rad(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
    return rect;
}
