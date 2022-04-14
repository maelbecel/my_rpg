/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void go_to_player(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 0;
}

void go_to_stat(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 1;
}

void go_to_quest(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 2;
}

void go_to_inventory(game_t* game, ...)
{
    game->scenes[MENU_PLAYER].tab->page = 3;
}

void add_hp(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->hp += 10;
        game->player->pt_stat -= 1;
    }
}

void add_strenght(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->strg += 1;
        game->player->pt_stat -= 1;
    }
}

void add_speed(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->spd += 1;
        game->player->pt_stat -= 1;
    }
}

void add_defense(game_t *game, ...)
{
    if (game->player->pt_stat > 0) {
        game->player->def += 1;
        game->player->pt_stat -= 1;
    }
}

void reset(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));
    game->player->hp = my_getnbr(parser(file, "health"));
    game->player->strg = my_getnbr(parser(file, "strength"));
    game->player->spd = my_getnbr(parser(file, "speed"));
    game->player->def = my_getnbr(parser(file, "defense"));
    game->player->pt_stat = my_getnbr(parser(file, "point_stat"));
}

button_t **menu_player_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    buttons[0] = init_button("PLAYER", "ressources/UI/button1.png",
                        (sfVector2f){25, 25}, (sfVector2i){300, 100});
    buttons[1] = init_button("STAT", "ressources/UI/button1.png",
                        (sfVector2f){492.5, 25}, (sfVector2i){300, 100});
    buttons[2] = init_button("QUEST", "ressources/UI/button1.png",
                        (sfVector2f){960, 25}, (sfVector2i){300, 100});
    buttons[3] = init_button("INVENTORY", "ressources/UI/button1.png",
                        (sfVector2f){1427.5, 25}, (sfVector2i){300, 100});
    buttons[4] = NULL;
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

    buttons[5] = NULL;
    buttons[0] = init_button("+", "ressources/UI/button1.png",
                        (sfVector2f){500, 150}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = add_hp;
    buttons[1] = init_button("+", "ressources/UI/button1.png",
                        (sfVector2f){500, 250}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = add_strenght;
    buttons[2] = init_button("+", "ressources/UI/button1.png",
                        (sfVector2f){500, 350}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = add_speed;
    buttons[3] = init_button("+", "ressources/UI/button1.png",
                        (sfVector2f){500, 450}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = add_defense;
    buttons[4] = init_button("RESET", "ressources/UI/button1.png",
                        (sfVector2f){100, 700}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = reset;
    buttons[4]->action_hoover = hoover_menu;
    for (int i = 0; i < 4; i++) {
        buttons[i]->action_hoover = hoover_menu;
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
    return buttons;
}

scene_t *menu_player_tab(void)
{
    scene_t *scenes = malloc(sizeof(scene_t) * 4);

    scenes->page = 0;
    scenes[STAT].buttons = init_button_stat();
    return scenes;
}
