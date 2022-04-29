/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

settings_t *init_settings(void)
{
    settings_t *set = malloc(sizeof(settings_t));

    if (!set)
        return NULL;
    set->font = sfFont_createFromFile(BASIC_FONT);
    if (!set->font)
        return NULL;
    set->key_down = int_from_json(SETTINGS_FILE, "down_key");
    set->key_up = int_from_json(SETTINGS_FILE, "up_key");
    set->key_left = int_from_json(SETTINGS_FILE, "left_key");
    set->key_right = int_from_json(SETTINGS_FILE, "right_key");
    set->key_pause = int_from_json(SETTINGS_FILE, "pause_key");
    set->key_menu = int_from_json(SETTINGS_FILE, "menu_key");
    set->key_action = int_from_json(SETTINGS_FILE, "action_key");
    set->key_skip = int_from_json(SETTINGS_FILE, "skip_key");
    set->music_volume = int_from_json(SETTINGS_FILE, "music_sound");
    set->fx_volume = int_from_json(SETTINGS_FILE, "fx_sound");
    return set;
}
