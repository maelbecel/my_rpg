/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void check_spider(game_t *game)
{
    if (get_nb_elem(game, "eye2") < 1)
        return;
    delete_element_n(game, "eye2", 1);
    add_element_n(game, "apple", 8);
    remove_quest(game, 1);
}

void check_apples(game_t *game)
{
    if (get_nb_elem(game, "apple") < 10)
        return;
    delete_element_n(game, "apple", 10);
    add_element_n(game, "jacket", 2);
    remove_quest(game, 2);
}

void check_rolling_pin(game_t *game)
{
    if (get_nb_elem(game, "rolling_pin") < 5)
        return;
    delete_element_n(game, "rolling_pin", 5);
    add_element_n(game, "gold", 10);
    add_elem(game, "gold_sword");
    remove_quest(game, 3);
}

void check_patrick(game_t *game)
{
    if (get_nb_elem(game, "beer") < 8)
        return;
    delete_element_n(game, "beer", 8);
    add_element_n(game, "ring", 3);
    add_element_n(game, "potion", 6);
    remove_quest(game, 4);
}

void check_dungeon(game_t *game)
{
    if (game->player->map == 2)
        return;
    delete_element_n(game, "key", 1);
    add_element_n(game, "potion", 15);
    remove_quest(game, 5);
}
