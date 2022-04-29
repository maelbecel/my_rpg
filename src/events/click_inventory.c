/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** click_inventory
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void hoover_inventory(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    sfSprite_setTexture(
            game->player->inventory[i]->button->hoover->sprite,
            sfTexture_createFromFile("assets/ui/button1_hoover.png", NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

void clicked_inventory(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    sfSprite_setTexture(
        game->player->inventory[i]->button->clicked->sprite,
        sfTexture_createFromFile("assets/ui/button1_clicked.png", NULL),
                                        sfTrue);
    va_end(arg);
    return;
}

int is_hoover_inventory(game_t *game, int i)
{
    sfVector2f pos = game->player->inventory[i]->button->pos;
    sfVector2f scale = game->player->inventory[i]->button->base->scale;
    sfVector2u size = sfTexture_getSize(
                                game->player->inventory[i]->button->hoover->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(game->window);

    size.x *= scale.x;
    size.y *= scale.y;
    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            game->player->inventory[i]->button->action_hoover(game, i);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int is_click_inventory(game_t *game, int i)
{
    if (!is_hoover_inventory(game, i) || !sfRenderWindow_isOpen(game->window))
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

void menu_inventory(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    sfVector2f pos = va_arg(arg, sfVector2f);
    pos.y += 150;
    if (game->is_inv)
        game->is_inv = false;
    else {
        game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[0]->pos = pos;
        game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[0]->pos.x -= 225;
        game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[1]->pos = pos;
        game->scenes[MENU_PLAYER].tab[INVENTORY].buttons[1]->pos.x += 125;
        game->is_inv = true;
    }
    va_end(arg);
}