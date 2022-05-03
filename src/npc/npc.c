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
    char *file = format("config/npc/%s.json", name);
    int *pos = int_array_from_json(file, "pos", NULL);

    npc->elem = init_element(format("assets/npc/%s.png", name),
                                    (sfVector2f){pos[0], pos[1]},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    npc->name = my_strdup(name);
    npc->merchant = int_from_json(file, "merchant");
    npc->quest = int_from_json(file, "quest");
    npc->text = str_from_json(file, "text");
    npc->map = int_from_json(file, "map");
    return npc;
}
