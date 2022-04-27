/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static char **get_trade_info(char *var, char *path)
{
    char *str = str_from_json(path, var);
    char **val = my_str_to_word_array(str, ' ');

    for (int i = 0; val[i]; i++) {
        if (val[i + 1] != NULL)
            val[i][my_strlen(val[i]) - 1] = '\0';
        val[i] = clean_string(val[i]);
    }
    return val;
}

static void fill_trade(trade_t ***trade, size_t i, char **want, char **sell)
{
    char **buf = NULL;

    buf = my_str_to_word_array(want[i], ',');
    (*trade)[i]->want = clean_string(buf[0]);
    (*trade)[i]->want_quantity = my_getnbr(buf[1]);
    buf = my_str_to_word_array(sell[i], ',');
    (*trade)[i]->give = clean_string(buf[0]);
    (*trade)[i]->give_quantity = my_getnbr(buf[1]);
    (*trade)[i + 1] = NULL;
}

trade_t **get_trade(npc_t *npc)
{
    char *path = conc("config/npc/", conc(npc->name, ".json"));
    char **want = get_trade_info("want", path);
    char **sell = get_trade_info("sell", path);
    trade_t **trade = malloc(sizeof(trade_t *) *
                                    my_strlen(str_from_json(path, "want")));

    if (!trade || !want || !sell || !path)
        return NULL;
    for (size_t i = 0; want[i]; i++) {
        trade[i] = malloc(sizeof(trade_t));
        if (!trade[i])
            return NULL;
        fill_trade(&trade, i, want, sell);
    }
    free(path);
    return (trade);
}
