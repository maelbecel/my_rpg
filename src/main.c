/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int get_fps(sfTime frame)
{
    float second = (float)frame.microseconds / (float)MICRO;
    return (int)(1 / second) + 1;
}

void draw_fps(sfTime frame, game_t *game)
{
    char *show;

    if ((show = parser(CONFIG_FILE, "show_fps")) != NULL &&
                                                        my_getnbr(show) == 1)
        draw_text_white(conc("FPS :", inttochar(get_fps(frame))), 40,
                                        (sfVector2f){50, 50}, game->window);
}

static int rpg(game_t *game, sfEvent *event)
{
    sfClock *fps = sfClock_create();
    sfTime frame;

    while (sfRenderWindow_isOpen(game->window)) {
        frame = sfClock_getElapsedTime(fps);
        sfClock_restart(fps);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            analyse_game_state(game, event, frame);
        }
        if (sfRenderWindow_isOpen(game->window) &&
            game->scenes->page == GAME) {
            display(game, event);
            draw_fps(frame, game);
            sfRenderWindow_display(game->window);
        }
    }
    return EXIT_SUCCESS;
}

static game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    if ((game->settings = init_settings()) == NULL)
        return NULL;
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 31);
    intro(game->window);
    sfRenderWindow_setFramerateLimit(game->window, 0);
    game->scenes = init_scenes(game->window);
    sfRenderWindow_setFramerateLimit(game->window,
                        int_from_json(CONFIG_FILE, "framerate"));
    game->player = init_player("chevalier");
    game->hitbox = sfImage_createFromFile(
                                        "assets/hitboxes/village_hitbox.png");
    return game;
}

int main(int ac, UNUSED char **argv)
{
    if (ac != 1)
        return 84;
    sfEvent event;
    game_t *game = init_game();

    if (!game)
        return EXIT_ERROR;
    rpg(game, &event);
    sfRenderWindow_destroy(game->window);
    free_all(game);
    free(game);
    return EXIT_SUCCESS;
}
