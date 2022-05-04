/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_battle
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void rescale(button_t **buttons)
{
    for (int i = 0; i < 3; i++) {
        buttons[i]->action_clicked = do_none;
        buttons[i]->base->scale = (sfVector2f){0.5, 0.7};
        buttons[i]->hoover->scale = (sfVector2f){0.5, 0.7};
        buttons[i]->clicked->scale = (sfVector2f){0.5, 0.7};
        buttons[i]->base->text_pos = (sfVector2f){50, 70};
        buttons[i]->hoover->text_pos = (sfVector2f){50, 70};
        buttons[i]->clicked->text_pos = (sfVector2f){50, 70};
    }
}

button_t **battle_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (3 + 1));

    if (!buttons)
        return NULL;
    buttons[0] = init_button("Escape", BUTTON, (sfVector2f){1500, 900},
                            (sfVector2i){796, 206});
    buttons[1] = init_button("Attack", BUTTON, (sfVector2f){1500, 740},
                            (sfVector2i){796, 206});
    buttons[2] = init_button("Inventory", BUTTON, (sfVector2f){1500, 580},
                            (sfVector2i){796, 206});
    rescale(buttons);
    buttons[0]->action_clicked = go_game;
    buttons[1]->action_clicked = attack;
    buttons[2]->action_clicked = open_inventory;
    buttons[3] = NULL;
    return buttons;
}

element_t **battle_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * (3 + 1));

    if (!elements)
        return NULL;
    elements[0] = init_element(BATTLE_BG, (sfVector2f){0, 0},
                        (sfVector2f){1050, 540}, (sfVector2f){2, 2});
    elements[1] = init_element(BUTTON,
        (sfVector2f){30, 780}, (sfVector2f){792, 206}, (sfVector2f){1.8, 1.3});
    elements[2] = NULL;
    elements[3] = NULL;
    if (!elements[0] || !elements[1])
        return NULL;
    return elements;
}

scene_t *tab_battle(void)
{
    scene_t *scenes = malloc(sizeof(scene_t));
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element("assets/ui/button_1_full.png",
                    (sfVector2f){0, 0}, (sfVector2f){1920, 1080},
                    (sfVector2f){1, 1});
    elements[1] = NULL;
    scenes->elements = elements;
    return scenes;
}

int init_battle(scene_t *scenes)
{
    if (!(scenes[BATTLE].buttons = battle_buttons()))
        return EXIT_FAILURE;
    if (!(scenes[BATTLE].elements = battle_elements()))
        return EXIT_FAILURE;
    scenes[BATTLE].tab = tab_battle();
    scenes[BATTLE].page = 0;
    return EXIT_SUCCESS;
}
