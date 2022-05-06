/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void fill_game(game_t *game)
{
    game->scenes->page = CHOOSING;
    game->scenes[GAME].elements[0]->rect.left = 0;
    game->scenes[GAME].elements[2]->pos.x = 800;
    game->scenes[GAME].elements[0]->rect.top = 0;
    game->scenes[GAME].elements[2]->pos.y = 800;
    game->player->xp = 0;
    game->player->map = 0;
    game->player->nbquest = 1;
    game->player->quest = malloc(sizeof(int));
    game->player->quest[0] = 0;
}

int new_game(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    i++;
    game->player->save[0] = i + '0';
    fill_game(game);
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    game->scenes[GAME].elements[0] = init_element("assets/forest_start.jpg",
            (sfVector2f){0, 0}, (sfVector2f){2500, 2500}, (sfVector2f){1, 1});
    game->hitbox = sfImage_createFromFile("assets/hitboxes/forest_hitbox.png");
    game->scenes[GAME].elements[5] = init_element("assets/forest_roof.png",
            (sfVector2f){0, 0}, (sfVector2f){2500, 2500}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6]->scale = (sfVector2f){0, 0};
    game->scenes[GAME].elements[0]->rect.top = 1300;
    game->scenes[GAME].elements[2]->pos.y -= 150;
    sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                        game->scenes[GAME].elements[6]->scale);
    lore(game->window);
    va_end(arg);
    return EXIT_SUCCESS;
}
