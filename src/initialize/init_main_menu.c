/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t **main_menu_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = NULL;
    // elements[0] = init_element("resource/UI/Mainmenu.png", (sfVector2f){0,0},
    //                             (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    return elements;
}

button_t **main_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    int i = 0;

    buttons[0] = init_button("PLAY", "ressources/UI/button1.png",
                        (sfVector2f){1200, 100}, (sfVector2i){300, 100});
    buttons[1] = init_button("HELP", "ressources/UI/button1.png",
                        (sfVector2f){1200, 300}, (sfVector2i){300, 100});
    buttons[2] = init_button("SETTINGS", "ressources/UI/button1.png",
                        (sfVector2f){1200, 500}, (sfVector2i){300, 100});
    buttons[3] = init_button("QUIT", "ressources/UI/button1.png",
                        (sfVector2f){1200, 700}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = quit;
    buttons[4] = NULL;
    while (buttons[i]) {
        buttons[i]->base->scale = (sfVector2f){4, 2};
        buttons[i]->clicked->scale = (sfVector2f){4, 2};
        buttons[i++]->hoover->scale = (sfVector2f){4, 2};
    }
    return buttons;
}