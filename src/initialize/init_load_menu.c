/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void new_game(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    i++;
    game->player->save[0] = i + '0';
    game->scenes->page = CHOOSING;
    va_end(arg);
}

void clear_1(UNUSED game_t *game, ...)
{
    char *file = my_strdup("saves/save1.json");
    update_file(file, "new", "1");
    update_file(file, "class", "null");
    update_file(file, "stength", "0");
    update_file(file, "speed", "0");
    update_file(file, "defense", "0");
    update_file(file, "health", "0");
    update_file(file, "point_stat", "0");
    game->scenes[LOAD].buttons[0]->action_clicked = new_game;
}

void clear_2(UNUSED game_t *game, ...)
{
    char *file = my_strdup("saves/save2.json");
    update_file(file, "new", "1");
    update_file(file, "class", "null");
    update_file(file, "stength", "0");
    update_file(file, "speed", "0");
    update_file(file, "defense", "0");
    update_file(file, "health", "0");
    update_file(file, "point_stat", "0");
    game->scenes[LOAD].buttons[1]->action_clicked = new_game;
}

void clear_3(UNUSED game_t *game, ...)
{
    char *file = my_strdup("saves/save3.json");
    update_file(file, "new", "1");
    update_file(file, "class", "null");
    update_file(file, "stength", "0");
    update_file(file, "speed", "0");
    update_file(file, "defense", "0");
    update_file(file, "health", "0");
    update_file(file, "point_stat", "0");
    game->scenes[LOAD].buttons[2]->action_clicked = new_game;
}

void load_1(game_t *game, ...)
{
    game->player->save[0] = '1';
    reset(game);
    game->scenes->page = GAME;
}

void load_2(game_t *game, ...)
{
    game->player->save[0] = '2';
    reset(game);
    game->scenes->page = GAME;
}

void load_3(game_t *game, ...)
{
    game->player->save[0] = '3';
    reset(game);
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
    button_t **buttons = malloc(sizeof(button_t *) * 7);

    buttons[0] = init_button("SAVE 1", "ressources/UI/button1.png",
                        (sfVector2f){50, 150}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = load_1;
    buttons[1] = init_button("SAVE 2", "ressources/UI/button1.png",
                        (sfVector2f){50, 400}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = load_2;
    buttons[2] = init_button("SAVE 3", "ressources/UI/button1.png",
                        (sfVector2f){50, 650}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = load_3;
    buttons[3] = init_button("CLEAR", "ressources/UI/button1.png",
                        (sfVector2f){850, 150}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = clear_1;
    buttons[4] = init_button("CLEAR", "ressources/UI/button1.png",
                        (sfVector2f){850, 400}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = clear_2;
    buttons[5] = init_button("CLEAR", "ressources/UI/button1.png",
                        (sfVector2f){850, 650}, (sfVector2i){300, 100});
    buttons[5]->action_clicked = clear_3;
    buttons[6] = NULL;
    buttons[0]->action_clicked = (my_getnbr(parser("saves/save1.json", "new")) == 1) ? new_game : buttons[0]->action_clicked;
    buttons[1]->action_clicked = (my_getnbr(parser("saves/save2.json", "new")) == 1) ? new_game : buttons[1]->action_clicked;
    buttons[2]->action_clicked = (my_getnbr(parser("saves/save3.json", "new")) == 1) ? new_game : buttons[2]->action_clicked;
    for (int i = 3; buttons[i]; i++) {
        buttons[i]->base->scale = (sfVector2f){0.3, 1};
        buttons[i]->base->text_pos = (sfVector2f){buttons[i]->base->text_pos.x - 200, buttons[i]->base->text_pos.y};
        buttons[i]->hoover->scale = (sfVector2f){0.3, 1};
        buttons[i]->hoover->text_pos = (sfVector2f){buttons[i]->hoover->text_pos.x - 200, buttons[i]->hoover->text_pos.y};
        buttons[i]->clicked->scale = (sfVector2f){0.3, 1};
        buttons[i]->clicked->text_pos = (sfVector2f){buttons[i]->clicked->text_pos.x - 200, buttons[i]->clicked->text_pos.y};
    }
    return buttons;
}