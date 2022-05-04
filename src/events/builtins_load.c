/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int load_file(game_t *game, char *file)
{
    sfVector2f getpos = (sfVector2f){int_from_json(file, "posx"),
                                    int_from_json(file, "posy")};

    if (my_strcmp(file, SAVE1) == 0)
        game->player->save[0] = '1';
    else if (my_strcmp(file, SAVE2) == 0)
        game->player->save[0] = '2';
    else
        game->player->save[0] = '3';
    check_save(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(file, "quests",
                                                    &game->player->nbquest);
    game->player->xp = int_from_json(file, "xp");
    game->player->map = int_from_json(file, "map");
    set_player_inventory(game, file);
    handle_map(game);
    set_player(game, getpos);
    return EXIT_SUCCESS;
}

int load_1(game_t *game, ...)
{
    return load_file(game, SAVE1);
}

int load_2(game_t *game, ...)
{
    return load_file(game, SAVE2);
}

int load_3(game_t *game, ...)
{
    return load_file(game, SAVE3);
}

int load(game_t *game, ...)
{
    for (int i = 0; i < SIZE_INVENTORY; i++) {
        game->player->inventory[i]->type = NULL;
        game->player->inventory[i]->value = 0;
        game->player->inventory[i]->elem = NULL;
    }
    game->scenes->page = LOAD;
    return EXIT_SUCCESS;
}
