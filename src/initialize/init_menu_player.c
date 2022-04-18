/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void update_scale(button_t **buttons)
{
    for (int i = 0; i < 4; i++) {
        buttons[i]->base->scale = (sfVector2f){0.59, 0.5};
        buttons[i]->clicked->scale = (sfVector2f){0.59, 0.5};
        buttons[i]->hoover->scale = (sfVector2f){0.59, 0.5};
        buttons[i]->base->text_pos.x *= 0.59;
        buttons[i]->base->text_pos.y *= 0.5;
        buttons[i]->clicked->text_pos.x *= 0.59;
        buttons[i]->clicked->text_pos.y *= 0.5;
        buttons[i]->hoover->text_pos.x *= 0.59;
        buttons[i]->hoover->text_pos.y *= 0.5;
    }
}

button_t **menu_player_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    buttons[0] = init_button("PLAYER", "ressources/ui/button1.png",
                        (sfVector2f){25, 25}, (sfVector2i){300, 100});
    buttons[1] = init_button("STAT", "ressources/ui/button1.png",
                        (sfVector2f){492.5, 25}, (sfVector2i){300, 100});
    buttons[2] = init_button("QUEST", "ressources/ui/button1.png",
                        (sfVector2f){960, 25}, (sfVector2i){300, 100});
    buttons[3] = init_button("INVENTORY", "ressources/ui/button1.png",
                        (sfVector2f){1427.5, 25}, (sfVector2i){300, 100});
    buttons[4] = NULL;
    update_scale(buttons);
    buttons[0]->action_clicked = go_to_player;
    buttons[1]->action_clicked = go_to_stat;
    buttons[2]->action_clicked = go_to_quest;
    buttons[3]->action_clicked = go_to_inventory;
    return buttons;
}

element_t **menu_player_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 3);
    elements[0] = init_element("ressources/menu/resume.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    elements[1] = NULL;
    elements[0]->rect = (sfIntRect){0, 0, 1920, 1080};
    return elements;
}

button_t **init_button_stat(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (5 + 1));

    buttons[0] = init_button("+", "ressources/ui/button1.png",
                        (sfVector2f){500, 150}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = add_hp;
    buttons[1] = init_button("+", "ressources/ui/button1.png",
                        (sfVector2f){500, 250}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = add_strenght;
    buttons[2] = init_button("+", "ressources/ui/button1.png",
                        (sfVector2f){500, 350}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = add_speed;
    buttons[3] = init_button("+", "ressources/ui/button1.png",
                        (sfVector2f){500, 450}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = add_defense;
    buttons[4] = init_button("RESET", "ressources/ui/button1.png",
                        (sfVector2f){100, 700}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = reset;
    buttons[4]->action_hoover = hoover_menu;
    update_stat(buttons);
    return buttons;
}

scene_t *menu_player_tab(void)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 4);

    scenes->page = 0;
    scenes[STAT].buttons = init_button_stat();
    return scenes;
}
