/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void update_pos(game_t *game, ...)
{
    char *file = format("saves/save%s.json", game->player->save);
    char *posx = inttochar(game->scenes[GAME].elements[0]->rect.left +
                                    game->scenes[GAME].elements[2]->pos.x);
    char *posy = inttochar(game->scenes[GAME].elements[0]->rect.top +
                                    game->scenes[GAME].elements[2]->pos.y);

    update_file(file, "posx", posx);
    update_file(file, "posy", posy);
    free(file);
    free(posx);
    free(posy);
}

int save(game_t *game, ...)
{
    char *file = format("saves/save%s.json", game->player->save);
    char *map = inttochar(game->player->map);
    char *hp = inttochar(game->player->hp);
    char *strg = inttochar(game->player->strg);
    char *spd = inttochar(game->player->spd);
    char *def = inttochar(game->player->def);
    char *pt = inttochar(game->player->pt_stat);
    char *xp = inttochar(game->player->xp);

    update_pos(game);
    update_file(file, "map", map);
    update_file(file, "health", hp), free(hp);
    update_file(file, "strength", strg), free(strg);
    update_file(file, "speed", spd), free(spd);
    update_file(file, "defense", def), free(def);
    update_file(file, "point_stat", pt);
    update_file(file, "xp", xp);
    update_inventory(game);
    free(file);
    return EXIT_SUCCESS;
}
