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
    char *file = format("config/npc/%s.json", name);
    int *pos = NULL;
    char *str = format("assets/npc/%s.png", name);

    if (!npc || !file)
        return NULL;
    if (!(pos = int_array_from_json(file, "pos", NULL)))
        return NULL;
    npc->elem = init_element(str, (sfVector2f){pos[0], pos[1]},
                                    (sfVector2f){32, 48}, (sfVector2f){2, 2});
    npc->name = my_strdup(name);
    npc->merchant = int_from_json(file, "merchant");
    npc->quest = int_from_json(file, "quest");
    npc->text = str_from_json(file, "text");
    npc->map = int_from_json(file, "map");
    free(file);
    free(str);
    return npc;
}
