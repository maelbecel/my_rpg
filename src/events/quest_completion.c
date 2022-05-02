/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static const struct quest_s Quests[] = {
    {0, NULL},
    {1, &check_spider},
    {2, &check_apples},
    {3, &check_rolling_pin},
    {4, &check_patrick},
    {5, &check_dungeon}
};

static char *int_array_to_string(int *array, int size)
{
    char *str = malloc(sizeof(char) * (size * 4));
    char *buf = "";
    int x = 1;

    str[0] = '[';
    for (int i = 0; i < size; i++) {
        buf = inttochar(array[i]);
        str[x++] = buf[0];
        if (i != size - 1) {
            str[x++] = ',';
            str[x++] = ' ';
        }
    }
    str[x++] = ']';
    str[x] = '\0';
    return str;
}

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

void remove_quest(game_t *game, int q)
{
    int *new = malloc(sizeof(int) * game->player->nbquest);
    int x = 0;
    char *save = conc("saves/save", conc(game->player->save, ".json"));

    for (int i = 0; i < game->player->nbquest; i++) {
        new[x] = game->player->quest[i];
        if (new[x] != q)
            x++;
    }
    free(game->player->quest);
    game->player->nbquest--;
    if (game->player->nbquest == 0){
        new[x] = 0;
        game->player->nbquest = 1;
    }
    game->player->quest = new;
    update_file(save, "quests", int_array_to_string(game->player->quest,
                                                game->player->nbquest));
}

void check_quest(game_t *game)
{
    if (game->player->quest[0] == 0)
        return;
    for (int i = 0; i < game->player->nbquest; i++) {
        my_printf("check for quest %i\n", game->player->quest[i]);
        Quests[game->player->quest[i]].func(game);
    }
}