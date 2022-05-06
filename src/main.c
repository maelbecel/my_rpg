/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int rpg(game_t *game, sfEvent *event)
{
    sfMusic_play(game->music[1].sound);
    game->fps = sfClock_create();
    if (!game->fps)
        return EXIT_ERROR;
    while (sfRenderWindow_isOpen(game->window)) {
        game->frame = sfClock_getElapsedTime(game->fps);
        sfClock_restart(game->fps);
        if (sfRenderWindow_pollEvent(game->window, event)) {
            analyse_game_state(game, event, game->frame);
            while (sfRenderWindow_pollEvent(game->window, event))
                analyse_game_state(game, event, game->frame);
        } else if (sfRenderWindow_isOpen(game->window)) {
            event->type = -1;
            if (display(game, event) == EXIT_FAILURE)
                return EXIT_ERROR;
        }
        if (draw_fps(game->frame, game) == EXIT_FAILURE)
            return EXIT_ERROR;
        sfRenderWindow_display(game->window);
    }
    sfClock_destroy(game->fps);
    return EXIT_SUCCESS;
}

static int do_intro(game_t *game)
{
    int frame = int_from_json(CONFIG_FILE, "framerate");

    if (frame == -1 || intro(game->window, -4, 249) == EXIT_FAILURE) {
        free(game);
        return EXIT_FAILURE;
    }
    sfRenderWindow_setFramerateLimit(game->window, 0);
    if (!(game->scenes = init_scenes(game->window)))
        return EXIT_FAILURE;
    if (!(game->scenes[GAME].npc = game_npc()))
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(game->window, frame);
    if (!(game->player = init_player("chevalier")))
        return EXIT_FAILURE;
    if (!(game->hitbox = sfImage_createFromFile(HITBOX)))
        return EXIT_FAILURE;
    if (!(game->weather = init_weather()))
        return EXIT_FAILURE;
    if (!(game->music = init_sound()))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->settings = init_settings();
    if (!game->settings || check_set(game->settings) == EXIT_FAILURE) {
        free(game);
        return NULL;
    }
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    if (!game->window) {
        free(game);
        return NULL;
    }
    sfRenderWindow_setFramerateLimit(game->window, 31);
    game->is_inv = false;
    if (do_intro(game) == EXIT_FAILURE)
        return NULL;
    return game;
}

int main(int ac, UNUSED char **argv)
{
    int exit_code = EXIT_SUCCESS;
    sfEvent event;
    game_t *game = init_game();

    if (ac != 1)
        return EXIT_ERROR;
    if (!game)
        return EXIT_ERROR;
    exit_code = rpg(game, &event);
    sfRenderWindow_destroy(game->window);
    free_all(game);
    free(game);
    return exit_code;
}
