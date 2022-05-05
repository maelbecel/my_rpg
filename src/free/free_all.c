/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void free_elements(element_t *elements)
{
    if (elements->texture)
        sfTexture_destroy(elements->texture);
    sfSprite_destroy(elements->sprite);
    free(elements);
}

void free_type(type_button_t *type)
{
    sfTexture_destroy(type->texture);
    sfSprite_destroy(type->sprite);
    sfText_destroy(type->text);
    sfFont_destroy(type->font);
    sfMusic_destroy(type->sound);
    free(type);
}

void free_button(button_t *button)
{
    free_type(button->base);
    free_type(button->hoover);
    free_type(button->clicked);
    free(button);
}

void free_all(game_t *game, ...)
{
    free_scenes(game);
    free_settings(game);
    free_player(game);
    free_weather(game);
    sfImage_destroy(game->hitbox);
}
