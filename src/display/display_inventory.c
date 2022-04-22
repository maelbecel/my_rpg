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
    draw_text(inttochar(inventory->value), game->settings->font,
    (sfVector3f){inventory->elem->pos.x + 100,
    inventory->elem->pos.y + 70, 40}, game->window);
}

void display_case_inventory(game_t *game, sfVector2f pos,
                            inventory_t *inventory)
{
    inventory->button->pos = pos;
    draw_button(game->window, inventory->button);
    if (inventory->elem != NULL) {
        draw_item(game, inventory, pos);
    }
}

void display_inventory(game_t *game, sfEvent *event)
{
    sfVector2f pos = (sfVector2f){100, 200};
    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 3);
    for (int i = 1; i < SIZE_INVENTORY + 1; i++) {
        display_case_inventory(game, pos, game->player->inventory[i - 1]);
        pos.x += 220;
        if (i % 8 == 0 && i != 0) {
            pos.y += 200;
            pos.x = 100;
        }
    }
}
