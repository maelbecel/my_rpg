/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_inventory
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_item(game_t *game, inventory_t *inventory, sfVector2f pos)
{
    inventory->elem->pos = pos;
    inventory->elem->pos.y += 35;
    inventory->elem->pos.x += 55;
    draw_element(game->window, inventory->elem);
    if (my_strlen(inttochar(inventory->value)) == 1)
        draw_text(inttochar(inventory->value), game->settings->font,
        (sfVector3f){inventory->elem->pos.x + 100,
        inventory->elem->pos.y + 70, 40}, game->window);
    else
        draw_text(inttochar(inventory->value), game->settings->font,
        (sfVector3f){inventory->elem->pos.x + 80,
        inventory->elem->pos.y + 70, 40}, game->window);
}

void display_case_inventory(game_t *game, sfVector2f pos,
                            inventory_t *inventory)
{
    inventory->button->pos = pos;
    // draw_button(game->window, inventory->button);
    if (inventory->elem != NULL) {
        draw_item(game, inventory, pos);
    }
}

void display_button_inventory(game_t *game, sfEvent *event)
{
    for (int i = 0; i < SIZE_INVENTORY; i++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click_inventory(game, i)) {
            draw_clicked(game->window, game->player->inventory[i]->button);
            game->player->inventory[i]->button->action_clicked(game,
                game->player->inventory[i]->button->pos);
        } else if (is_hoover_inventory(game, i))
            draw_hoover(game->window, game->player->inventory[i]->button);
        else
            draw_button(game->window, game->player->inventory[i]->button);
    }
}

void display_tab_inventory(game_t *game, sfEvent *event)
{
    inventory_t *tmp = find_item(game,
                        game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[0]);
    if (!tmp)
        return;
    for (int i = 0; i < 2; i++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click_menu(game, i, MENU_PLAYER, INVENTORY)) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[i]);
            game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[i]->\
                action_clicked(game, tmp->type);
        } else if (is_hoover_menu(game, i, MENU_PLAYER, INVENTORY))
            draw_hoover(game->window, game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[i]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[i]);
    }
}

void display_inventory(game_t *game, sfEvent *event)
{
    sfVector2f pos = (sfVector2f){100, 200};
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 3);
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
