/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef INIT
    #define INIT
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    typedef struct game_s game_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct settings_s settings_t;
    typedef struct type_button_s type_button_t;

    button_t **main_menu_buttons(void);
    element_t **main_menu_elements(void);
    button_t **game_buttons(void);
    element_t **game_elements(void);
    button_t **settings_buttons(void);
    element_t **settings_elements(void);
    button_t **menu_player_buttons(void);
    element_t **menu_player_elements(void);
    button_t **settings_key_buttons(void);
    element_t **settings_key_elements(void);
    element_t **settings_sounds_elements(void);
    button_t **settings_sounds_buttons(void);
    button_t **htp_first_buttons(void);
    element_t **htp_first_elements(void);
    button_t **htp_second_buttons(void);
    element_t **htp_second_elements(void);
    button_t **htp_third_buttons(void);
    element_t **htp_third_elements(void);
    element_t **pause_elements(void);
    button_t **pause_buttons(void);

    scene_t *init_scenes(void);
    element_t *init_element(char *texture, sfVector2f pos,
                        sfVector2f size, sfVector2f scale);
    button_t *init_button(char *text, char *texture,
                        sfVector2f pos, sfVector2i size);
    type_button_t *init_button_type(char *text, char *texture,
                                    sfVector2i size);
    settings_t *init_settings(void);

#endif
