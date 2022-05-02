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
    update_file(SAVE1, "new", "1");
    update_file(SAVE1, "class", "null");
    update_file(SAVE1, "stength", "0");
    update_file(SAVE1, "speed", "0");
    update_file(SAVE1, "xp", "0");
    update_file(SAVE1, "defense", "0");
    update_file(SAVE1, "health", "0");
    update_file(SAVE1, "point_stat", "0");
    update_file(SAVE1, "posx", "800");
    update_file(SAVE1, "map", "0");
    update_file(SAVE1, "posy", "800");
    update_file(SAVE1, "quests", "[0]");
    update_file(SAVE1, "inventory", format("[\"none\"]"););
    game->scenes[LOAD].buttons[0]->action_clicked = new_game;
}

format("[\"none\"]");

void clear_2(UNUSED game_t *game, ...)
{
    update_file(SAVE2, "new", "1");
    update_file(SAVE2, "xp", "0");
    update_file(SAVE2, "class", "null");
    update_file(SAVE2, "stength", "0");
    update_file(SAVE2, "speed", "0");
    update_file(SAVE2, "defense", "0");
    update_file(SAVE2, "health", "0");
    update_file(SAVE2, "point_stat", "0");
    update_file(SAVE2, "map", "0");
    update_file(SAVE2, "posx", "800");
    update_file(SAVE2, "posy", "800");
    update_file(SAVE2, "quests", "[0]");
    update_file(SAVE2, "inventory", format("[\"none\"]"););
    game->scenes[LOAD].buttons[1]->action_clicked = new_game;
}

void clear_3(UNUSED game_t *game, ...)
{
    update_file(SAVE3, "new", "1");
    update_file(SAVE3, "class", "null");
    update_file(SAVE3, "stength", "0");
    update_file(SAVE3, "speed", "0");
    update_file(SAVE3, "defense", "0");
    update_file(SAVE3, "xp", "0");
    update_file(SAVE3, "health", "0");
    update_file(SAVE3, "map", "0");
    update_file(SAVE3, "point_stat", "0");
    update_file(SAVE3, "posx", "800");
    update_file(SAVE3, "posy", "800");
    update_file(SAVE3, "quests", "[0]");
    update_file(SAVE3, "inventory", format("[\"none\"]"););
    game->scenes[LOAD].buttons[2]->action_clicked = new_game;
}
