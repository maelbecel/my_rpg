/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t **choosing_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 8);
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = init_element(CROSSBOW_P, (sfVector2f){400, 120},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[2] = init_element(ARCHER_P, (sfVector2f){900, 120},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[3] = init_element(KNIGHT_P, (sfVector2f){1400, 120},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[4] = init_element(COOKER_P, (sfVector2f){400, 630},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[5] = init_element(MAGE_P, (sfVector2f){900, 630},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[6] = init_element(VALKYRIE_P, (sfVector2f){1400, 630},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    elements[7] = NULL;
    return elements;
}

static void more_choosing_buttons(button_t **buttons)
{
    buttons[3] = init_button("", "assets/ui/button1.png",
                        (sfVector2f){250, 560}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = cuisiniere;
    buttons[4] = init_button("", "assets/ui/button1.png",
                        (sfVector2f){750, 560}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = mage;
    buttons[5] = init_button("", "assets/ui/button1.png",
                        (sfVector2f){1250, 560}, (sfVector2i){300, 100});
    buttons[5]->action_clicked = valkyrie;
}

button_t **choosing_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 7);

    buttons[0] = init_button("", "assets/ui/button1.png",
                        (sfVector2f){250, 40}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = arbaletier;
    buttons[1] = init_button("", "assets/ui/button1.png",
                        (sfVector2f){750, 40}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = archere;
    buttons[2] = init_button("", "assets/ui/button1.png",
                        (sfVector2f){1250, 40}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = chevalier;
    buttons[6] = NULL;
    more_choosing_buttons(buttons);
    for (int i = 0; buttons[i]; i++) {
        buttons[i]->base->scale = (sfVector2f){0.5, 2.5};
        buttons[i]->hoover->scale = (sfVector2f){0.5, 2.5};
        buttons[i]->clicked->scale = (sfVector2f){0.5, 2.5};
    }
    return buttons;
}
