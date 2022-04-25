/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>


static game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->settings = init_settings();
    if (game->settings == NULL)
        return NULL;
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    game->scenes = init_scenes(game->window);
    game->player = init_player("chevalier");
    game->player->save = "1";
    game->hitbox = sfImage_createFromFile(
                                        "assets/hitboxes/hitbox.png");
    return game;
}

Test(Display, Draw_xp_bar, .timeout = 20)
{
    game_t *game = init_game();

    game->player->xp = 2000;
    cr_assert_not_null(game);
    draw_xp_bar(game);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Draw_npc, .timeout = 20)
{
    game_t *game = init_game();
    npc_t *npc = create_npc("pascal");

    cr_assert_not_null(game);
    draw_npc(game, npc);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_frame, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_frame(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Draw_choosing, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_choosing(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}
