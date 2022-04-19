/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

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
    update_file(file, "posx", "900");
    update_file(file, "posy", "500");
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
    update_file(file, "posx", "900");
    update_file(file, "posy", "500");
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
    update_file(file, "posx", "900");
    update_file(file, "posy", "500");
    game->scenes[LOAD].buttons[2]->action_clicked = new_game;
}
