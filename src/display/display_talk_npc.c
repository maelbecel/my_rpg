/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_trade(game_t *game, sfVector2f pos_get, sfVector2f pos_want,
                trade_t *trade)
{
    element_t *get = init_element(conc("assets/icons/",conc(trade->want, ".png")),
                                pos_get, (sfVector2f){32, 32},
                                (sfVector2f){3, 3});
    element_t *want = init_element(conc("assets/icons/",conc(trade->give, ".png")),
                                pos_want, (sfVector2f){32, 32},
                                (sfVector2f){3, 3});
    draw_element(game->window, get);
    draw_element(game->window, want);
    draw_text("->", game->settings->font, (sfVector3f){760, pos_want.y, 70},
                game->window);
    free_elements(get);
    free_elements(want);
}

void display_trade(game_t *game, trade_t **trade)
{
    sfVector2f pos_get = {600, 200};
    sfVector2f pos_want = {900, 200};

    for (int i = 0; trade[i] != NULL; i++) {
        draw_trade(game, pos_get, pos_want, trade[i]);
        pos_get.y += 100;
        pos_want.y += 100;
    }
}

void display_merchant(game_t *game, npc_t *npc)
{
    trade_t **trade = get_trade(npc);
    game->scenes[NPC].elements[1] = init_element(conc("assets/npc/",
        conc(npc->name, ".png")), (sfVector2f){100, 150}, (sfVector2f){32, 48},
        (sfVector2f){8, 8});
    for (int e = 0; game->scenes[NPC].elements[e]; e++)
        draw_element(game->window, game->scenes[NPC].elements[e]);
    for (int b = 0; game->scenes[NPC].buttons[b]; b++)
        draw_button(game->window, game->scenes[NPC].buttons[b]);
    display_trade(game, trade);
    free_elements(game->scenes[NPC].elements[1]);
}

void display_talk_npc(game_t *game, sfEvent *event)
{
    npc_t *npc = find_npc(game);

    for (int e = 0; game->scenes[GAME].elements[e]; e++)
        draw_element(game->window, game->scenes[GAME].elements[e]);
    display_npc(game);
    if (npc->merchant == true) {
        display_merchant(game, npc);
    }
    draw_dialogue_box(game->window, conc(npc->name, conc(" :\n", npc->text)),
                                                        game->settings->font);
    draw_pop_text(conc("Press '", conc(getkey(game->settings->key_skip),
                        "'\nto leave")), game->settings->font, game->window);
    if (event->key.code == game->settings->key_skip)
        go_game(game);
}