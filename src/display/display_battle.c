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
    char *file = format("saves/save%s.json", game->player->save);

    game->player->pt_stat += 3;
    update_file(file, "pt_stat", inttochar(game->player->pt_stat));
    game->player->xp += game->enemy->exp;
    my_printf("Beat %s\n", game->enemy->name);
    for (int i = 0; game->enemy->loot[i]; i++)
        add_elem(game, clean_string(game->enemy->loot[i]));
    if (my_strcmp(game->enemy->name, "The Boss") == 0)
        lore_outro(game->window);
    go_game(game);
}

void display_inventory_battle(game_t *game, sfEvent *event)
{
    sfVector2f pos = (sfVector2f){100, 200};

    if (event->type == sfEvtKeyPressed &&
        event->key.code == game->settings->key_menu)
        game->scenes[BATTLE].page = 0;
    draw_element(game->window, game->scenes[BATTLE].tab[0].elements[0]);
    display_button_inventory(game, event);
    for (int i = 1; i < SIZE_INVENTORY + 1; i++) {
        display_case_inventory(game, pos, game->player->inventory[i - 1]);
        pos.x += 220;
        if (i % 8 == 0 && i != 0) {
            pos.y += 200;
            pos.x = 100;
        }
    }
    if (game->is_inv)
        display_tab_inventory(game, event);
}

static void check_win(game_t *game, sfEvent *event)
{
    if (game->enemy->life <= 0) {
        win(game, event);
        return;
    } if (game->player->stat->hp <= 0) {
        go_game(game);
        return;
    }
    draw_text(game->enemy->buf_text, game->settings->font,
                    (sfVector3f){100, 850, 50}, game->window);
    draw_life(game->enemy->life, game->enemy->total_life, game,
                (sfVector2f){1222, 330});
    draw_life(game->player->stat->hp, game->player->total_hp, game,
                (sfVector2f){515, 530});
}

void display_normal_battle(game_t *game, sfEvent *event)
{
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
    check_win(game, event);
}

int display_battle(game_t *game, sfEvent *event)
{
    if (game->scenes[BATTLE].page == 0) {
        display_normal_battle(game, event);
    } else {
        display_inventory_battle(game, event);
    }
    return EXIT_SUCCESS;
}
