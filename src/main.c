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
    return (int)(1 / second);
}

static void draw_fps(sfTime frame, game_t *game)
{
    char *show;

    if ((show = parser("config/config.json", "show_fps")) != NULL &&
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
            if (analyse_event(game, event) == 0)
                return 0;
            if (game->scenes->page == MENU_PLAYER &&
                game->scenes[MENU_PLAYER].tab->page == STAT)
                event_menu_player(game, event);
        }
        display(game, event);
        draw_fps(frame, game);
        sfRenderWindow_display(game->window);
    }
    return 0;
}

game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    game->settings = init_settings();
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window,
                        my_getnbr(parser("config/config.json", "framerate")));
    intro(game->window);
    game->scenes = init_scenes(game->window);
    game->player = init_player("chevalier");
    return game;
}

int main(int ac, UNUSED char **argv)
{
    if (ac != 1)
        return 84;
    sfEvent event;
    game_t *game = init_game();
    rpg(game, &event);
    sfRenderWindow_destroy(game->window);
    return 0;
}
