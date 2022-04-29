/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t *init_element(char *texture, sfVector2f pos,
                        sfVector2f size, sfVector2f scale)
{
    element_t *type = malloc(sizeof(element_t));

    if (!type)
        return NULL;
    if (!(type->texture = sfTexture_createFromFile(texture, NULL)))
        return NULL;
    if (!(type->sprite = sfSprite_create()))
        return NULL;
    type->scale = scale;
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    type->pos = pos;
    sfSprite_setTexture(type->sprite, type->texture, sfFalse);
    sfSprite_setTextureRect(type->sprite, type->rect);
    sfSprite_setScale(type->sprite, type->scale);
    return type;
}
