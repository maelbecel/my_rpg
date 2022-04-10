/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void go_to_inventory(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 1;
}

void go_to_stat(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 0;
}

button_t **menu_player_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    buttons[0] = init_button("STAT", "ressources/UI/button1.png",
                        (sfVector2f){0, 0}, (sfVector2i){300, 100});
    buttons[1] = init_button("INVENTORY", "ressources/UI/button1.png",
                        (sfVector2f){480, 0}, (sfVector2i){300, 100});
    buttons[2] = NULL;
    buttons[0]->base->scale = (sfVector2f){0.6, 0.5};
    buttons[0]->clicked->scale = (sfVector2f){0.6, 0.5};
    buttons[0]->hoover->scale = (sfVector2f){0.6, 0.5};
    buttons[0]->action_clicked = go_to_stat;
    buttons[1]->base->scale = (sfVector2f){0.6, 0.5};
    buttons[1]->clicked->scale = (sfVector2f){0.6, 0.5};
    buttons[1]->hoover->scale = (sfVector2f){0.6, 0.5};
    buttons[1]->action_clicked = go_to_inventory;
    return buttons;
}

element_t **menu_player_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 3);
    elements[0] = init_element("ressources/menu/bg_menu.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = NULL;
    elements[0]->rect = (sfIntRect){0, 0, 1920, 1080};
    return elements;
}

scene_t *menu_player_tab(void)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 1);

    scenes->page = 0;
    return scenes;
}