/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int addlevel(int xp)
{
    int level = 1;
    for (; xp >= 500 * level * level; level++);
    level += (my_random() % level + 1) - level / 2 - level / 4;
    if (level < 1)
        return 1;
    return level;
}

enemy_t *create_enemy(char *type, player_t *player)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    char *file = format("config/enemy/%s.json", type);
    char *texture = str_from_json(file, "image");

    enemy->elem = init_element(texture, ENEMY_POS,
                                (sfVector2f){32, 48}, BATTLE_SCALE);
    enemy->name = str_from_json(file, "name");
    enemy->text = str_array_from_json(file, "text");
    enemy->level = (my_strcmp(type, "boss") == 0) ? 20 : addlevel(player->xp);
    enemy->life = int_from_json(file, "life") * enemy->level;
    enemy->total_life = int_from_json(file, "life") * enemy->level;
    enemy->damage = int_from_json(file, "damage") * enemy->level;
    enemy->exp = int_from_json(file, "exp") * enemy->level;
    enemy->loot = str_array_from_json(file, "loot");
    enemy->buf_text = format("It's a %s of level %d", enemy->name,
                                                                enemy->level);
    free(file);
    free(texture);
    return enemy;
}
