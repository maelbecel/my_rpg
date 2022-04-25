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
    sfRenderWindow_setFramerateLimit(game->window, 31);
    sfRenderWindow_setFramerateLimit(game->window, 0);
    game->scenes = init_scenes(game->window);
    sfRenderWindow_setFramerateLimit(game->window,
                        int_from_json(CONFIG_FILE, "framerate"));
    game->player = init_player("chevalier");
    game->player->save = "1";
    game->hitbox = sfImage_createFromFile(
                                        "assets/hitboxes/hitbox.png");
    return game;
}


Test(Class, Arbaletier)
{
    game_t *game = init_game();
    arbaletier(game);
    cr_assert_eq(game->scenes->page, GAME);
    cr_assert_eq(game->player->hp, int_from_json("config/arbaletier.json",
                                                                "health"));
    cr_assert_eq(game->player->strg, int_from_json("config/arbaletier.json",
                                                                "strength"));
    cr_assert_eq(game->player->spd, int_from_json("config/arbaletier.json",
                                                                "speed"));
    cr_assert_eq(game->player->def, int_from_json("config/arbaletier.json",
                                                                "defense"));
}

Test(Class, Archere)
{
    game_t *game = init_game();
    archere(game);
    cr_assert_eq(game->scenes->page, GAME);
    cr_assert_eq(game->player->hp, int_from_json("config/archere.json",
                                                                "health"));
    cr_assert_eq(game->player->strg, int_from_json("config/archere.json",
                                                                "strength"));
    cr_assert_eq(game->player->spd, int_from_json("config/archere.json",
                                                                "speed"));
    cr_assert_eq(game->player->def, int_from_json("config/archere.json",
                                                                "defense"));
}