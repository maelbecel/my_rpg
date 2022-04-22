/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

npc_t *create_npc(char *name)
{
    npc_t *npc = malloc(sizeof(npc_t));

    if (!npc)
        return NULL;
    int *pos = int_array_from_json(conc("config/npc/", conc(name, ".json")),
                                    "pos", NULL);

    npc->elem = init_element(conc("assets/npc/", conc(name, ".png")),
                (sfVector2f){pos[0], pos[1]}, (sfVector2f){32, 48},
                (sfVector2f){2, 2});
    npc->name = my_strdup(name);
    npc->merchant = int_from_json(conc("config/npc/", conc(name, ".json")),
                    "merchant");
    npc->quest = int_from_json(conc("config/npc/", conc(name, ".json")),
                    "quest");
    npc->text = str_from_json(conc("config/npc/", conc(name, ".json")),
                    "text");
    return npc;
}