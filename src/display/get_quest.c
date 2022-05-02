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
    "No quest curently",
    "Kill a spider",
    "Collect 10 apples",
    "Buy 5 rolling pin",
    "Collect 8 beers from Patrick",
    "Enter in the dungeon"
};

char *clean_string(char *str)
{
    int i = 1;
    char *res = malloc(sizeof(char) * my_strlen(str));

    if (!res || !str)
        return NULL;
    for (; str[i]; i++)
        res[i - 1] = str[i];
    res[i - 2] = '\0';
    return res;
}

static char *get_buf(char *buf, char *str, int size)
{
    char *buffer = my_strdup(buf);

    buffer = conc(buffer, my_strdup(Quests[my_getnbr(str)]));
    if (my_getnbr(str) != 0)
        buffer = conc(buffer, conc(" (", conc(str, conc("/", conc(
                                                    inttochar(size), ")")))));
    buffer = conc(buffer, "\n");
    return buffer;
}

static bool error_case(game_t *game, char **array, int i, int size)
{
    if (my_getnbr(array[i]) > size || my_getnbr(array[i]) < 0) {
        popup(game->settings->font,
                            conc("\t\t\tCannot load quest ", array[i]));
        game->scenes[MENU_PLAYER].tab->page = PLAYER;
        return true;
    } if (my_strarraylen(array) != 1 && my_getnbr(array[i]) == 0) {
        popup(game->settings->font, "\t\tCorrupted save for quests");
        game->scenes[MENU_PLAYER].tab->page = PLAYER;
        return true;
    }
    return false;
}

char *get_quests(game_t *game)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));
    char **array = str_array_from_json(file, "quests");
    char *buffer = "";
    int size = sizeof(Quests) / sizeof(char *) - 1;

    if (!array)
        return NULL;
    for (int i = 0; array[i]; i++) {
        if (error_case(game, array, i, size))
            return "";
        buffer = get_buf(buffer, array[i], size);
        free(array[i]);
    }
    free(file);
    free(array);
    return buffer;
}
