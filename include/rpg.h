/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef RPG
    #define RPG
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

    #include "cinematique.h"
    #include "event.h"

    #define UNUSED __attribute__((unused))
    #define BASIC_TEXT_SIZE 50
    #define BASIC_FONT "ressources/Fonts/game.ttf"

    #define MICRO 1000000

    typedef struct type_button_s type_button_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct game_s game_t;
    typedef struct settings_s settings_t;

    enum scenes {
        MAIN_MENU,
        GAME,
        SETTINGS,
        MENU_PLAYER
    };

    struct element_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfVector2f pos;
        int max_sprite;
    };

    struct type_button_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfText *text;
        sfFont *font;
        sfMusic *sound;
        sfVector2f text_pos;
        int text_size;
    };

    struct button_s {
        type_button_t *base;
        type_button_t *hoover;
        type_button_t *clicked;
        sfVector2f pos;
        void (*action_hoover)(game_t *game, ...);
        void (*action_clicked)(game_t *game, ...);
        int x;
        int y;
    };

    struct scene_s {
        button_t **buttons;
        element_t **elements;
        int page;
    };

    struct settings_s {
        int volume;
        int key_up;
        int key_down;
        int key_left;
        int key_right;
        int key_pause;
        int key_menu;
    };

    struct game_s {
        sfRenderWindow *window;
        scene_t *scenes;
        settings_t *settings;
    };

    //display
    void draw_button(sfRenderWindow *window, button_t *button);
    void draw_hoover(sfRenderWindow *window, button_t *button);
    void draw_clicked(sfRenderWindow *window, button_t *button);
    void draw_element(sfRenderWindow *window, element_t *element);

    void display(game_t *game, sfEvent *event);

    //initialize
    button_t **main_menu_buttons(void);
    element_t **main_menu_elements(void);
    button_t **game_buttons(void);
    element_t **game_elements(void);
    button_t **settings_buttons(void);
    element_t **settings_elements(void);
    button_t **menu_player_buttons(void);
    element_t **menu_player_elements(void);

    scene_t *init_scenes(void);
    element_t *init_element(char *texture, sfVector2f pos,
                        sfVector2f size, sfVector2f scale);
    button_t *init_button(char *text, char *texture,
                        sfVector2f pos, sfVector2i size);
    type_button_t *init_button_type(char *text, char *texture,
                                    sfVector2i size);
    settings_t *init_settings(void);

#endif
