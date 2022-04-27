/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void arrow(game_t *game, trade_t *trade, sfVector2f pos_want)
{
    if (get_nb_elem(game, trade->want) >= trade->want_quantity)
        draw_text_green("->", game->settings->font,
            (sfVector3f){760, pos_want.y, 70}, game->window);
    else
        draw_text_red("->", game->settings->font,
                (sfVector3f){760, pos_want.y, 70}, game->window);
}

void draw_trade(game_t *game, sfVector2f pos_get, sfVector2f pos_want,
                trade_t *trade)
{
    element_t *want = init_element(conc("assets/icons/",
                    conc(trade->want, ".png")), pos_get, (sfVector2f) {32, 32},
                                                        (sfVector2f) {3, 3});
    element_t *get = init_element(conc("assets/icons/",
                conc(trade->give, ".png")), pos_want, (sfVector2f) {32, 32},
                                                        (sfVector2f) {3, 3});
    draw_element(game->window, want);
    draw_text(inttochar(trade->want_quantity), game->settings->font,
            (sfVector3f){pos_get.x + 90, pos_get.y + 70, 50}, game->window);
    draw_text(inttochar(trade->give_quantity), game->settings->font,
            (sfVector3f){pos_want.x + 90, pos_want.y + 70, 50}, game->window);
    draw_element(game->window, get);
    arrow(game, trade, pos_want);
    free_elements(get);
    free_elements(want);
}

void display_trade(game_t *game, trade_t **trade, sfEvent *event)
{
    sfVector2f pos_get = {600, 200};
    sfVector2f pos_want = {900, 200};

    for (int i = 0; trade[i] != NULL; i++) {
        draw_trade(game, pos_get, pos_want, trade[i]);
        draw_button(game->window, game->scenes[NPC].buttons[i]);
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, i, NPC)) {
            draw_clicked(game->window, game->scenes[NPC].buttons[i]);
            game->scenes[NPC].buttons[i]->action_clicked(game, trade[i]->give,
            trade[i]->want, trade[i]->give_quantity, trade[i]->want_quantity);
        } else if (is_hoover(game, i, NPC))
            draw_hoover(game->window, game->scenes[NPC].buttons[i]);
        else
            draw_button(game->window, game->scenes[NPC].buttons[i]);
        pos_get.y += 150;
        pos_want.y += 150;
    }
}

void display_merchant(game_t *game, npc_t *npc, sfEvent *event)
{
    trade_t **trade = get_trade(npc);

    game->scenes[NPC].elements[1] = init_element(conc("assets/npc/",
        conc(npc->name, ".png")), (sfVector2f){100, 150}, (sfVector2f){32, 48},
        (sfVector2f){8, 8});
    for (int e = 0; game->scenes[NPC].elements[e]; e++)
        draw_element(game->window, game->scenes[NPC].elements[e]);
    display_trade(game, trade, event);
    free_elements(game->scenes[NPC].elements[1]);
}

void display_talk_npc(game_t *game, sfEvent *event)
{
    npc_t *npc = find_npc(game);

    for (int e = 0; game->scenes[GAME].elements[e]; e++)
        draw_element(game->window, game->scenes[GAME].elements[e]);
    display_npc(game);
    if (npc->merchant == true) {
        display_merchant(game, npc, event);
    }
    draw_dialogue_box(game->window, conc(npc->name, conc(" :\n", npc->text)),
                                                        game->settings->font);
    draw_pop_text(conc("Press '", conc(getkey(game->settings->key_skip),
                        "'\nto leave")), game->settings->font, game->window);
    if (event->key.code == game->settings->key_skip)
        go_game(game);
}
