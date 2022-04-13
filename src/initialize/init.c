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

void init_settings_menu(scene_t *scenes, sfRenderWindow *window)
{
    scenes[SETTINGS].buttons = settings_buttons();
    loading(7, window);
    scenes[SETTINGS].elements = settings_elements();
    loading(8, window);
    scenes[SOUNDS].buttons = settings_sounds_buttons();
    loading(9, window);
    scenes[SOUNDS].elements = settings_sounds_elements();
    loading(10, window);
    scenes[KEY].buttons = settings_key_buttons();
    loading(11, window);
    scenes[KEY].elements = settings_key_elements();
    loading(12, window);
}

scene_t *init_scenes(sfRenderWindow *window)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 11);
    scenes->page = 0;
    scenes[MAIN_MENU].buttons = main_menu_buttons();
    loading(0, window);
    scenes[MAIN_MENU].elements = main_menu_elements();
    loading(1, window);
    scenes[GAME].buttons = game_buttons();
    loading(2, window);
    scenes[GAME].elements = game_elements();
    loading(3, window);
    scenes[MENU_PLAYER].buttons = menu_player_buttons();
    loading(4, window);
    scenes[MENU_PLAYER].elements = menu_player_elements();
    loading(5, window);
    scenes[MENU_PLAYER].tab = menu_player_tab();
    loading(6, window);
    init_settings_menu(scenes, window);
    scenes[PAUSE].buttons = pause_buttons();
    loading(13, window);
    scenes[PAUSE].elements = pause_elements();
    loading(14, window);
    init_htp(scenes, window);
    scenes[LOAD].buttons = load_menu_buttons();
    loading(21, window);
    scenes[LOAD].elements = load_menu_elements();
    loading(22, window);
    return scenes;
}

settings_t *init_settings(void)
{
    settings_t *set = malloc(sizeof(settings_t));
    set->key_down = my_getnbr(parser("config/settings.json", "down_key"));
    set->key_up = my_getnbr(parser("config/settings.json", "up_key"));
    set->key_left = my_getnbr(parser("config/settings.json", "left_key"));
    set->key_right = my_getnbr(parser("config/settings.json", "right_key"));
    set->key_pause = my_getnbr(parser("config/settings.json", "pause_key"));
    set->key_menu = my_getnbr(parser("config/settings.json", "menu_key"));
    set->music_volume = my_getnbr(parser("config/settings.json",
                                                            "music_sound"));
    set->fx_volume = my_getnbr(parser("config/settings.json", "fx_sound"));
    return set;
}