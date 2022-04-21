/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t **load_menu_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 2);
    elements[0] = init_element(BACKGROUND, (sfVector2f){0, 0},
                        (sfVector2f){2000, 2000}, (sfVector2f){1, 1});
    elements[1] = NULL;
    return elements;
}

static void check_sve(button_t **buttons)
{
    buttons[0]->action_clicked =
            (int_from_json("saves/save1.json", "new") == 1) ?
                                        new_game : buttons[0]->action_clicked;
    buttons[1]->action_clicked =
            (int_from_json("saves/save2.json", "new") == 1) ?
                                        new_game : buttons[1]->action_clicked;
    buttons[2]->action_clicked =
            (int_from_json("saves/save3.json", "new") == 1) ?
                                        new_game : buttons[2]->action_clicked;
}

static void fill_buttons(button_t **buttons)
{
    buttons[0] = init_button("SAVE 1", "ressources/ui/button1.png",
                        (sfVector2f){50, 150}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = load_1;
    buttons[1] = init_button("SAVE 2", "ressources/ui/button1.png",
                        (sfVector2f){50, 400}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = load_2;
    buttons[2] = init_button("SAVE 3", "ressources/ui/button1.png",
                        (sfVector2f){50, 650}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = load_3;
    buttons[3] = init_button("CLEAR", "ressources/ui/button1.png",
                        (sfVector2f){850, 150}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = clear_1;
    buttons[4] = init_button("CLEAR", "ressources/ui/button1.png",
                        (sfVector2f){850, 400}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = clear_2;
    buttons[5] = init_button("CLEAR", "ressources/ui/button1.png",
                        (sfVector2f){850, 650}, (sfVector2i){300, 100});
    buttons[5]->action_clicked = clear_3;
    buttons[6] = NULL;
}

button_t **load_menu_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 7);

    fill_buttons(buttons);
    check_sve(buttons);
    for (int i = 3; buttons[i]; i++) {
        buttons[i]->base->scale = (sfVector2f){0.3, 1};
        buttons[i]->base->text_pos =
                            (sfVector2f){buttons[i]->base->text_pos.x - 200,
                            buttons[i]->base->text_pos.y};
        buttons[i]->hoover->scale = (sfVector2f){0.3, 1};
        buttons[i]->hoover->text_pos =
                            (sfVector2f){buttons[i]->hoover->text_pos.x - 200,
                            buttons[i]->hoover->text_pos.y};
        buttons[i]->clicked->scale = (sfVector2f){0.3, 1};
        buttons[i]->clicked->text_pos =
                            (sfVector2f){buttons[i]->clicked->text_pos.x - 200,
                            buttons[i]->clicked->text_pos.y};
    }
    return buttons;
}
