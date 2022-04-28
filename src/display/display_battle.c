/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void win(game_t *game, ...)
{
    game->player->pt_stat += 3;
    game->player->xp += game->enemy->exp;
    for (int i = 0; game->enemy->loot[i]; i++)
        add_elem(game, clean_string(game->enemy->loot[i]));
    go_game(game);
}

void display_battle(game_t *game, sfEvent *event)
{
    if (game->enemy->life <= 0) {
        win(game, event);
        return;
    }
    for (int i = 0; game->scenes[BATTLE].elements[i] != NULL; i++)
        draw_element(game->window, game->scenes[BATTLE].elements[i]);
    draw_element(game->window, game->enemy->elem);
    for (int i = 0; game->scenes[BATTLE].buttons[i] != NULL; i++){
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, i, BATTLE)) {
            draw_clicked(game->window, game->scenes[BATTLE].buttons[i]);
            game->scenes[BATTLE].buttons[i]->action_clicked(game);
        } else if (is_hoover(game, i, BATTLE))
            draw_hoover(game->window, game->scenes[BATTLE].buttons[i]);
        else
            draw_button(game->window, game->scenes[BATTLE].buttons[i]);
    }
    draw_text(game->enemy->buf_text, game->settings->font,
                    (sfVector3f){100, 900, 50}, game->window);
    draw_life(game->enemy->life, game->enemy->total_life, game,
                (sfVector2f){1300, 300});
    return;
}
