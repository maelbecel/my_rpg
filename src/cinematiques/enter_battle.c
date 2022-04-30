/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static bool skip(sfRenderWindow *window)
{
    int key = int_from_json(SETTINGS_FILE , "skip_key");
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return true;
    return false;
}

static void draw_game(game_t *game)
{
    for (int e = 0; game->scenes[GAME].elements[e];)
        draw_element(game->window, game->scenes[GAME].elements[e++]);
    display_npc(game);
    for (int b = 0; game->scenes[GAME].buttons[b];)
        draw_button(game->window, game->scenes[GAME].buttons[b++]);
}

static void draw_battle(game_t *game)
{
    for (int i = 0; game->scenes[BATTLE].elements[i] != NULL; i++)
        draw_element(game->window, game->scenes[BATTLE].elements[i]);
    draw_element(game->window, game->enemy->elem);
    for (int i = 0; game->scenes[BATTLE].buttons[i] != NULL; i++)
        draw_button(game->window, game->scenes[BATTLE].buttons[i]);
    draw_text(game->enemy->buf_text, game->settings->font,
                    (sfVector3f){100, 850, 50}, game->window);
    draw_life(game->enemy->life, game->enemy->total_life, game,
                (sfVector2f){1222, 330});
    draw_life(game->player->hp, game->player->total_hp, game,
                (sfVector2f){515, 530});
    return;
}

int battle(game_t *game, ...)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    element_t *bg = init_element("assets/cinematiques/transition.png",
        (sfVector2f){-3010, 0}, (sfVector2f){3000, 1080}, (sfVector2f){1, 1});

    while (bg->pos.x < 1920 && !skip(game->window)) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds / 1000  < 0.01)
            continue;
        sfClock_restart(clock);
        bg->pos.x += 20;
        sfRenderWindow_clear(game->window, sfBlack);
        if (bg->pos.x < -40)
            draw_game(game);
        else
            draw_battle(game);
        draw_element(game->window, bg);
        sfRenderWindow_display(game->window);
    }
    return EXIT_SUCCESS;
}
