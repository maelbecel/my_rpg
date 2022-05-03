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

void remove_quest(game_t *game, int q)
{
    int *new = malloc(sizeof(int) * game->player->nbquest);
    int x = 0;
    char *save = format("saves/save%s.json", game->player->save);

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
        Quests[game->player->quest[i]].func(game);
    }
}