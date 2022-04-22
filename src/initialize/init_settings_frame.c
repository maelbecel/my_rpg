/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void up_frame(game_t *game, ...)
{
    int i = int_from_json(CONFIG_FILE, "framerate");
    if (i < 200) {
        i += 10;
        update_file(CONFIG_FILE, "framerate", inttochar(i));
        sfRenderWindow_setFramerateLimit(game->window, i);
    }
}

static void down_frame(game_t *game, ...)
{
    int i = int_from_json(CONFIG_FILE, "framerate");
    if (i > 20) {
        i -= 10;
        update_file(CONFIG_FILE, "framerate", inttochar(i));
        sfRenderWindow_setFramerateLimit(game->window, i);
    }
}

static void shower(game_t *game, ...)
{
    (void)game;
    if (int_from_json(CONFIG_FILE, "show_fps") == 0) {
        update_file(CONFIG_FILE, "show_fps", "1");
    } else {
        update_file(CONFIG_FILE, "show_fps", "0");
    }
}

element_t **settings_elements_frame(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);

    if (!elements)
        return NULL;
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    return elements;
}

button_t **settings_buttons_frame(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    int i = 0;

    if (!buttons)
        return NULL;
    buttons[0] = init_button("FRAME -           ", BUTTON,
                        (sfVector2f){500, 400}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = down_frame;
    buttons[1] = init_button("FRAME +           ", BUTTON,
                        (sfVector2f){1100, 400}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = up_frame;
    buttons[2] = init_button("<-             ", BUTTON,
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = settings;
    buttons[3] = init_button("Show fps :\t\t\t\t", BUTTON,
                        (sfVector2f){560, 650}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = shower;
    buttons[4] = NULL;
    while (i < 3) {
        buttons[i]->base->scale = (sfVector2f){0.4, 1};
        buttons[i]->clicked->scale = (sfVector2f){0.4, 1};
        buttons[i++]->hoover->scale = (sfVector2f){0.4, 1};
    }
    return buttons;
}
