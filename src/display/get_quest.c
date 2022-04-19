/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static const char *Quests[] = {
    "No quest actually",
    "Talk to the forgeron",
    "Talk to the blacksmith",
    "Talk to the alchemist",
    "Talk to the priest",
    "Talk to the merchant",
    "Talk to the innkeeper",
    "Talk to the farmer",
    "Talk to the butcher",
    "Talk to the baker"
};

char *clean_string(char *str)
{
    int i = 1;
    char *res = malloc(sizeof(char) * my_strlen(str));

    for (; str[i]; i++)
        res[i - 1] = str[i];
    res[i - 2] = '\0';
    return res;
}

char *get_quests(game_t *game)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));
    char **array = my_str_to_word_array(clean_string(parser(file, "quests")), ',');
    char *buffer = "";

    for(int i = 0; array[i]; i++) {
        buffer = conc(buffer, my_strdup(Quests[my_getnbr(array[i])]));
        buffer = conc(buffer, "\n");
    }
    return buffer;
}