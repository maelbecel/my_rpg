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

    if (!type)
        return NULL;
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

    if (!button)
        return NULL;
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

    if (!type)
        return NULL;
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

scene_t *init_scenes(sfRenderWindow *window)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 13);

    if (!scenes)
        return NULL;
    scenes->page = 0;
    scenes[MAIN_MENU].buttons = main_menu_buttons();
    loading(0, window);
    scenes[MAIN_MENU].elements = main_menu_elements();
    loading(1, window);
    scenes[GAME].buttons = game_buttons();
    loading(2, window);
    scenes[GAME].elements = game_elements();
    loading(3, window);
    init_menu_player(scenes, window);
    init_settings_menu(scenes, window);
    init_htp(scenes, window);
    init_new_game(scenes, window);
    for (int i = 0; i < 13; i++)
        scenes[i].tab = (i != MENU_PLAYER) ? NULL : scenes[i].tab;
    return scenes;
}

settings_t *init_settings(void)
{
    settings_t *set = malloc(sizeof(settings_t));

    if (!set)
        return NULL;
    set->font = sfFont_createFromFile(BASIC_FONT);
    set->key_down = int_from_json(SETTINGS_FILE, "down_key");
    set->key_up = int_from_json(SETTINGS_FILE, "up_key");
    set->key_left = int_from_json(SETTINGS_FILE, "left_key");
    set->key_right = int_from_json(SETTINGS_FILE, "right_key");
    set->key_pause = int_from_json(SETTINGS_FILE, "pause_key");
    set->key_menu = int_from_json(SETTINGS_FILE, "menu_key");
    set->key_action = int_from_json(SETTINGS_FILE, "action_key");
    set->key_skip = int_from_json(SETTINGS_FILE, "skip_key");
    set->music_volume = int_from_json(SETTINGS_FILE,
                                                            "music_sound");
    set->fx_volume = int_from_json(SETTINGS_FILE, "fx_sound");
    return set;
}
