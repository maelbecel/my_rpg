/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_battle
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void attack(game_t *game, ...)
{
    int x = my_random() % game->enemy->damage - game->player->def;
    if (x < 0)
        game->enemy->buf_text = conc(game->enemy->name, " missed his attack !");
    else
        game->enemy->buf_text = conc(game->enemy->name, conc(" say :\n", clean_string(game->enemy->text[my_random() % my_strarraylen(game->enemy->text)])));
    game->enemy->life -= game->player->strg;
    game->player->hp = (x > 0) ? game->player->hp - x : game->player->hp;
}

button_t **battle_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * (3 + 1));

    if (!buttons)
        return NULL;
    buttons[0] = init_button("Fuite", BUTTON, (sfVector2f){1500, 900},
                            (sfVector2i){796, 206});
    buttons[1] = init_button("Attack", BUTTON, (sfVector2f){1500, 740},
                            (sfVector2i){796, 206});
    buttons[2] = init_button("Inventory", BUTTON, (sfVector2f){1500, 580},
                            (sfVector2i){796, 206});
    for (int i = 0; i < 3; i++) {
        buttons[i]->action_clicked = do_none;
        buttons[i]->base->scale = (sfVector2f){0.5, 0.7};
        buttons[i]->hoover->scale = (sfVector2f){0.5, 0.7};
        buttons[i]->clicked->scale = (sfVector2f){0.5, 0.7};
        buttons[i]->base->text_pos.x = 70;
        buttons[i]->base->text_pos.y = 50;
        buttons[i]->hoover->text_pos.x = 70;
        buttons[i]->hoover->text_pos.y = 50;
        buttons[i]->clicked->text_pos.x = 70;
        buttons[i]->clicked->text_pos.y = 50;
    }
    buttons[0]->action_clicked = go_game;
    buttons[1]->action_clicked = attack;
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
    elements[1]= init_element(BUTTON,
        (sfVector2f){30, 780}, (sfVector2f){792, 206}, (sfVector2f){1.8, 1.3});
    elements[2] = NULL;
    elements[3] = NULL;
    if (!elements[0] || !elements[1])
        return NULL;
    return elements;
}

int init_battle(scene_t *scenes)
{
    if (!(scenes[BATTLE].buttons = battle_buttons()))
        return EXIT_FAILURE;
    if (!(scenes[BATTLE].elements = battle_elements()))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}