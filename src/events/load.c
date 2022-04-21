/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void new_game(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    i++;
    game->player->save[0] = i + '0';
    game->scenes->page = CHOOSING;
    game->scenes[GAME].elements[0]->rect.left = 0;
    game->scenes[GAME].elements[2]->pos.x = 900;
    game->scenes[GAME].elements[0]->rect.top = 0;
    game->scenes[GAME].elements[2]->pos.y = 500;
    va_end(arg);
}

void load_1(game_t *game, ...)
{
    sfVector2f getpos = (sfVector2f){int_from_json(SAVE1, "posx"),
                                    int_from_json(SAVE1, "posy")};

    game->player->save[0] = '1';
    check_save(game);
    set_player(game, getpos);
    reset(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(SAVE1, "quests",
                                                    &game->player->nbquest);
    set_player_inventory(game, SAVE1);
}

void load_2(game_t *game, ...)
{
    sfVector2f getpos = (sfVector2f){int_from_json(SAVE2, "posx"),
        int_from_json(SAVE2, "posy")};

    game->player->save[0] = '2';
    check_save(game);
    set_player(game, getpos);
    reset(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(SAVE2, "quests",
                                                    &game->player->nbquest);
    set_player_inventory(game, SAVE2);
}

void load_3(game_t *game, ...)
{
    sfVector2f getpos = (sfVector2f){int_from_json(SAVE3, "posx"),
        int_from_json(SAVE3, "posy")};

    game->player->save[0] = '3';
    check_save(game);
    set_player(game, getpos);
    reset(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(SAVE3, "quests",
                                                    &game->player->nbquest);
    set_player_inventory(game, SAVE3);
}

void load(game_t *game, ...)
{
    game->player->inventory[0]->type = NULL;
    game->scenes->page = LOAD;
}
