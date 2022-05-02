/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int init_settings_menu(scene_t *scenes, sfRenderWindow *window)
{
    scenes[SETTINGS].buttons = settings_buttons(), loading(7, window);
    scenes[SETTINGS].elements = settings_elements(), loading(8, window);
    scenes[SOUNDS].buttons = settings_sounds_buttons(), loading(9, window);
    scenes[SOUNDS].elements = settings_sounds_elements(), loading(10, window);
    scenes[KEY].buttons = settings_key_buttons(), loading(11, window);
    scenes[KEY].elements = settings_key_elements(), loading(12, window);
    scenes[PAUSE].buttons = pause_buttons(), loading(13, window);
    scenes[PAUSE].elements = pause_elements(), loading(14, window);
    scenes[FRAME].buttons = settings_buttons_frame(), loading(15, window);
    scenes[FRAME].elements = settings_elements_frame(), loading(16, window);
    return EXIT_SUCCESS;
}

int init_menu_player(scene_t *scenes, sfRenderWindow *window)
{
    if (!(scenes[MENU_PLAYER].buttons = menu_player_buttons()))
        return EXIT_FAILURE;
    loading(4, window);
    if (!(scenes[MENU_PLAYER].elements = menu_player_elements()))
        return EXIT_FAILURE;
    loading(5, window);
    if (!(scenes[MENU_PLAYER].tab = menu_player_tab()))
        return EXIT_FAILURE;
    loading(6, window);
    return EXIT_SUCCESS;
}

int init_new_game(scene_t *scenes, sfRenderWindow *window)
{
    if (!(scenes[LOAD].buttons = load_menu_buttons()))
        return EXIT_FAILURE;
    loading(23, window);
    if (!(scenes[LOAD].elements = load_menu_elements()))
        return EXIT_FAILURE;
    loading(24, window);
    if (!(scenes[CHOOSING].buttons = choosing_buttons()))
        return EXIT_FAILURE;
    loading(25, window);
    if (!(scenes[CHOOSING].elements = choosing_elements()))
        return EXIT_FAILURE;
    loading(26, window);
    return EXIT_SUCCESS;
}

int init_other_scenes(sfRenderWindow *window, scene_t *scenes)
{
    if (init_menu_player(scenes, window) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_settings_menu(scenes, window)== EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_htp(scenes, window)== EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_new_game(scenes, window)== EXIT_FAILURE)
        return EXIT_FAILURE;
    if (init_talk_npc(scenes)== EXIT_FAILURE)
        return EXIT_FAILURE;
    set_tab(scenes);
    if (init_battle(scenes)== EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

scene_t *init_scenes(sfRenderWindow *window)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 15);

    if (!scenes)
        return NULL;
    scenes->page = 0;
    if (!(scenes[MAIN_MENU].buttons = main_menu_buttons()))
        return NULL;
    loading(0, window);
    if (!(scenes[MAIN_MENU].elements = main_menu_elements()))
        return NULL;
    loading(1, window);
    if (!(scenes[GAME].buttons = game_buttons()))
        return NULL;
    loading(2, window);
    if (!(scenes[GAME].elements = game_elements()))
        return NULL;
    loading(3, window);
    if (init_other_scenes(window, scenes) == EXIT_FAILURE)
        return NULL;
    return scenes;
}
