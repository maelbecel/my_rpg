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
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    #define UNUSED __attribute__((unused))

    typedef struct type_button_s type_button_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct game_s game_t;

    enum scenes {
        MAIN_MENU
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
        void (*action_hoover)(scene_t *scenes, ...);
        void (*action_clicked)(scene_t *scenes, ...);
        int x;
        int y;
    };

    struct scene_s {
        button_t **buttons;
        element_t **elements;
        int page;
    };

    struct game_s {
        sfRenderWindow *window;
        scene_t *scenes;
    };

    int analyse_event(sfRenderWindow *window, sfEvent *event);

#endif
