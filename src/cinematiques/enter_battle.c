/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

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
    draw_life(game->player->stat->hp, game->player->total_hp, game,
                (sfVector2f){515, 530});
    return;
}

void init_stat_battle(game_t *game)
{
    game->player->stat->hp = game->player->total_hp;
    game->player->stat->strg = game->player->strg;
    game->player->stat->def = game->player->def;
    game->player->stat->spd = game->player->spd;
}

int battle(game_t *game, ...)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    element_t *bg = init_element("assets/cinematiques/transition.png",
        (sfVector2f){-3600, 0}, (sfVector2f){3500, 1080}, (sfVector2f){1, 1});

    sfMusic_play(game->music[0].sound), init_stat_battle(game);
    while (bg->pos.x < 3600 && !skip(game->window)) {
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds / 1000  < 0.01)
            continue;
        sfClock_restart(clock);
        bg->pos.x += 20;
        sfRenderWindow_clear(game->window, sfBlack);
        if (bg->pos.x < -500)
            draw_game(game);
        else
            draw_battle(game);
        draw_element(game->window, bg), sfRenderWindow_display(game->window);
    }
    sfClock_destroy(clock);
    return EXIT_SUCCESS;
}
