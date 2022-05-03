/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_battle
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int attack(game_t *game, ...)
{
    int x = my_random() % game->enemy->damage - game->player->stat->def;
    if (x < 0)
        game->enemy->buf_text = format("%s missed his attack !",
                                                        game->enemy->name);
    else
        game->enemy->buf_text = format("%s say:\n%s", game->enemy->name,
                                clean_string(game->enemy->text[my_random() %
                                my_strarraylen(game->enemy->text)]));
    game->enemy->life -= game->player->stat->strg;
    game->player->stat->hp = (x > 0) ? game->player->stat->hp - x :
                                                    game->player->stat->hp;
    return EXIT_SUCCESS;
}