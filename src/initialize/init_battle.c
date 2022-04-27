/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_battle
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

button_t **battle_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (3 + 1));

    buttons[0] = init_button("Fuite", BUTTON, (sfVector2f){700, 850},
                            (sfVector2i){796, 206});
    buttons[0]->action_clicked = go_game;
    buttons[1] = init_button("Attack", BUTTON, (sfVector2f){300, 600},
                            (sfVector2i){796, 206});
    buttons[2] = init_button("Inventory", BUTTON, (sfVector2f){1100, 600},
                            (sfVector2i){796, 206});
    for (int i = 0; i < 3; i++) {
        buttons[i]->base->scale = (sfVector2f){0.7, 0.9};
        buttons[i]->hoover->scale = (sfVector2f){0.7, 0.9};
        buttons[i]->clicked->scale = (sfVector2f){0.7, 0.9};
        buttons[i]->base->text_pos.x = 70;
        buttons[i]->base->text_pos.y = 50;
        buttons[i]->hoover->text_pos.x = 70;
        buttons[i]->hoover->text_pos.y = 50;
        buttons[i]->clicked->text_pos.x = 70;
        buttons[i]->clicked->text_pos.y = 50;
    }
    buttons[3] = NULL;
    return buttons;
}

element_t **battle_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * (1 + 1));

    elements[0] = init_element(BATTLE_BG, (sfVector2f){0, 0},
                        (sfVector2f){1050, 540}, (sfVector2f){2, 2});
    elements[1] = NULL;
    return elements;
}

void init_battle(scene_t *scenes)
{
    scenes[BATTLE].buttons = battle_buttons();
    scenes[BATTLE].elements = battle_elements();
}