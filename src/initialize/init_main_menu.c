/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void main_menu(game_t *game, ...)
{
    game->scenes->page = MAIN_MENU;
}

element_t **main_menu_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/village.jpg", (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **main_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);

    buttons[0] = init_button("PLAY", "ressources/ui/button1.png",
                        (sfVector2f){1200, 90}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = load;
    buttons[1] = init_button("HELP", "ressources/ui/button1.png",
                        (sfVector2f){1200, 300}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = htp_first;
    buttons[2] = init_button("SETTINGS", "ressources/ui/button1.png",
                        (sfVector2f){1200, 510}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = settings;
    buttons[3] = init_button("QUIT", "ressources/ui/button1.png",
                        (sfVector2f){1200, 720}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = quit;
    buttons[4] = NULL;
    return buttons;
}
