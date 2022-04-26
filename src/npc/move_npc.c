/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int heigher(int up, int down, int left, int right)
{
    if (up > down && up > left && up > right)
        return 0;
    if (down > up && down > left && down > right)
        return 3;
    if (left > up && left > down && left > right)
        return 2;
    if (right > up && right > down && right > left)
        return 1;
    return (0);
}

static int getdistance(sfVector2f npcpos, sfVector2f playerpos)
{
    int distance = 0;

    distance = (npcpos.x - playerpos.x) * (npcpos.x - playerpos.x) +
    (npcpos.y - playerpos.y) * (npcpos.y - playerpos.y);
    return sqrt(distance);
}

static int get_higher_distance(game_t *game, sfVector2f npcpos, int i,
                                                sfVector2f playerpos)
{
    int up = getdistance((sfVector2f){npcpos.x +
    (game->scenes[GAME].npc[i]->elem->rect.width / 2), npcpos.y}, playerpos);
    int left = getdistance((sfVector2f){npcpos.x, npcpos.y +
    (game->scenes[GAME].npc[i]->elem->rect.height / 2)}, playerpos);
    int down = getdistance((sfVector2f){npcpos.x +
    (game->scenes[GAME].npc[i]->elem->rect.width / 2), npcpos.y +
    (game->scenes[GAME].npc[i]->elem->rect.height)}, playerpos);
    int right = getdistance((sfVector2f){npcpos.x +
    (game->scenes[GAME].npc[i]->elem->rect.width), npcpos.y +
    (game->scenes[GAME].npc[i]->elem->rect.height / 2)}, playerpos);
    return heigher(up, down, left, right);
}

void move_npc(game_t *game, sfVector2f npcpos, sfVector2f playerpos, int i)
{
    int x = get_higher_distance(game, npcpos, i, playerpos);

    game->scenes[GAME].npc[i]->elem->rect.top =
                            x * game->scenes[GAME].npc[i]->elem->rect.height;
    sfSprite_setTextureRect(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->rect);
}
