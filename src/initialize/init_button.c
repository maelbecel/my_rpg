/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

type_button_t *init_button_type(char *text, char *texture, sfVector2i size)
{
    type_button_t *type = malloc(sizeof(type_button_t));

    if (!type || !(type->texture = sfTexture_createFromFile(texture, NULL)))
        return NULL;
    if (!(type->sprite = sfSprite_create()))
        return NULL;
    type->scale = (sfVector2f) {1, 1};
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    if (!(type->text = sfText_create()))
        return NULL;
    if (!(type->font = sfFont_createFromFile(BASIC_FONT)))
        return NULL;
    type->text_size = BASIC_TEXT_SIZE;
    type->text_pos = (sfVector2f){(size.x - my_strlen(text) *
            (BASIC_TEXT_SIZE / 4 )), (size.y - BASIC_TEXT_SIZE +
            (BASIC_TEXT_SIZE) / 4)};
    type->sound = NULL;
    sfText_setString(type->text, text);
    sfSprite_setTexture(type->sprite, type->texture, sfTrue);
    return type;
}

button_t *init_button(char *text, char *texture,
                    sfVector2f pos, sfVector2i size)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    if (!(button->base = init_button_type(text, texture, size)))
        return NULL;
    if (!(button->hoover = init_button_type(text, texture, size)))
        return NULL;
    if (!(button->clicked = init_button_type(text, texture, size)))
        return NULL;
    button->pos.x = pos.x;
    button->pos.y = pos.y;
    button->action_clicked = clicked;
    button->action_hoover = hoover;
    return button;
}
