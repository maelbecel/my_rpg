/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

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
    scenes[PAUSE].buttons = pause_buttons();
    loading(13, window);
    scenes[PAUSE].elements = pause_elements();
    loading(14, window);
    scenes[FRAME].buttons = settings_buttons_frame();
    loading(15, window);
    scenes[FRAME].elements = settings_elements_frame();
    loading(16, window);
}

void init_menu_player(scene_t *scenes, sfRenderWindow *window)
{
    scenes[MENU_PLAYER].buttons = menu_player_buttons();
    loading(4, window);
    scenes[MENU_PLAYER].elements = menu_player_elements();
    loading(5, window);
    scenes[MENU_PLAYER].tab = menu_player_tab();
    loading(6, window);
}

void init_new_game(scene_t *scenes, sfRenderWindow *window)
{
    scenes[LOAD].buttons = load_menu_buttons();
    loading(23, window);
    scenes[LOAD].elements = load_menu_elements();
    loading(24, window);
    scenes[CHOOSING].buttons = choosing_buttons();
    loading(25, window);
    scenes[CHOOSING].elements = choosing_elements();
    loading(26, window);
}
