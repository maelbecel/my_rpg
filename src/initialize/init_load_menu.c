/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void load_1(game_t *game, ...)
{
    game->scenes->page = GAME;
}

void load_2(game_t *game, ...)
{
    game->scenes->page = GAME;
}

void load_3(game_t *game, ...)
{
    game->scenes->page = GAME;
}

void new_game(game_t *game, ...)
{
    game->scenes->page = GAME;
}

void load(game_t *game, ...)
{
    game->scenes->page = LOAD;
}

element_t **load_menu_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("ressources/map.png", (sfVector2f){0, 0},
                        (sfVector2f){10001, 10080}, (sfVector2f){0.2, 0.2});
    elements[1] = NULL;
    return elements;
}

button_t **load_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);

    buttons[0] = init_button("SAVE 1", "ressources/UI/button1.png",
                        (sfVector2f){50, 50}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = load_1;
    buttons[1] = init_button("SAVE 2", "ressources/UI/button1.png",
                        (sfVector2f){50, 250}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = load_2;
    buttons[2] = init_button("SAVE 3", "ressources/UI/button1.png",
                        (sfVector2f){50, 450}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = load_3;
    buttons[3] = init_button("NEW GAME", "ressources/UI/button1.png",
                        (sfVector2f){50, 650}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = new_game;
    buttons[4] = NULL;
    return buttons;
}
