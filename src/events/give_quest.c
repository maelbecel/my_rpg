/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static bool quest_already_give(game_t *game, int quest)
{
    for (int i = 0; i < game->player->nbquest; i++) {
        if (game->player->quest[i] == quest)
            return true;
    }
    return false;
}

static int *add_quest(int *quest, int nb, int quest_give)
{
    int *new_quest = malloc(sizeof(int) * (nb + 1));

    for (int i = 0; i < nb; i++)
        new_quest[i] = quest[i];
    new_quest[nb] = quest_give;
    free(quest);
    return new_quest;
}

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

void give_quest(game_t *game, npc_t *npc)
{
    char *file = format("config/npc/%s.json", npc->name);
    int quest = int_from_json(file, "quest");
    char *save = format("saves/save%s.json", game->player->save);

    if (quest == 0 || quest_already_give(game, quest))
        return;
    if (game->player->quest[0] == 0) {
        game->player->quest[0] = npc->quest;
        update_file(save, "quests", format("[%i]", npc->quest));
    }
    else {
        game->player->quest = add_quest(game->player->quest,
                                            game->player->nbquest, npc->quest);
        game->player->nbquest++;
        update_file(save, "quests", int_array_to_string(game->player->quest,
                                                game->player->nbquest));
    }
}