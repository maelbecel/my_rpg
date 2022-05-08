/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int up_frame(game_t *game, ...)
{
    int i = int_from_json(CONFIG_FILE, "framerate");
    char *value = inttochar(i + 10);

    if (i < 200) {
        update_file(CONFIG_FILE, "framerate", value);
        sfRenderWindow_setFramerateLimit(game->window, i + 10);
    }
    free(value);
    return EXIT_SUCCESS;
}

static int down_frame(game_t *game, ...)
{
    int i = int_from_json(CONFIG_FILE, "framerate");
    char *value = inttochar(i - 10);

    if (i > 20) {
        update_file(CONFIG_FILE, "framerate", value);
        sfRenderWindow_setFramerateLimit(game->window, i - 10);
    }
    free(value);
    return EXIT_SUCCESS;
}

static int shower(game_t *game, ...)
{
    (void)game;
    if (int_from_json(CONFIG_FILE, "show_fps") == 0) {
        update_file(CONFIG_FILE, "show_fps", "1");
    } else {
        update_file(CONFIG_FILE, "show_fps", "0");
    }
    return EXIT_SUCCESS;
}

element_t **settings_elements_frame(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);

    if (!elements)
        return NULL;
    elements[0] = init_element(TITLE, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    return elements;
}

button_t **settings_buttons_frame(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 6);

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
    buttons[4] = init_button("Show particles :\t\t\t", BUTTON,
                        (sfVector2f){560, 860}, (sfVector2i){300, 100});
    rescale_frame(buttons);
    return buttons;
}
