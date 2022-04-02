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
    type->texture = sfTexture_createFromFile(texture, NULL);
    type->sprite = sfSprite_create();
    type->scale = (sfVector2f) {1, 1};
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    type->text = sfText_create();
    type->font = sfFont_createFromFile(BASIC_FONT);
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
    button->base = init_button_type(text, texture, size);
    button->hoover = init_button_type(text, texture, size);
    button->clicked = init_button_type(text, texture, size);
    button->pos.x = pos.x;
    button->pos.y = pos.y;
    button->action_clicked = clicked;
    button->action_hoover = hoover;
    return button;
}

element_t *init_element(char *texture, sfVector2f pos,
                        sfVector2f size, sfVector2f scale)
{
    element_t *type = malloc(sizeof(element_t));
    type->texture = sfTexture_createFromFile(texture, NULL);
    type->sprite = sfSprite_create();
    type->scale = scale;
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    type->pos = pos;
    sfSprite_setTexture(type->sprite, type->texture, sfFalse);
    sfSprite_setTextureRect(type->sprite, type->rect);
    sfSprite_setScale(type->sprite, type->scale);
    return type;
}

scene_t *init_scenes(void)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 5);
    scenes->page = 0;
    scenes[0].buttons = main_menu_buttons();
    scenes[0].elements = main_menu_elements();
    scenes[1].buttons = game_buttons();
    scenes[1].elements = game_elements();
    return scenes;
}

settings_t *init_settings(void)
{
    settings_t *set = malloc(sizeof(settings_t));
    set->key_down = sfKeyDown;
    set->key_up = sfKeyUp;
    set->key_left = sfKeyLeft;
    set->key_right = sfKeyRight;
    set->key_pause = sfKeyEscape;
    set->volume = 50;
    return set;
}