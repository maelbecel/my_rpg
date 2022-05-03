/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static sfRectangleShape *init_rect(float number)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){480, 840});
    sfRectangleShape_setSize(rect, (sfVector2f){960 * (number / 100), 100});
    return rect;
}

void draw_load(int at, int on, sfRenderWindow *window)
{
    sfRectangleShape *rect = init_rect((float)(at + 1) / (on) * 100);

    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(10, 200, 50));
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

static int get_xp_for_level(int level)
{
    return (500 * level * level);
}

void draw_xp_bar(game_t *game)
{
    int xp  = game->player->xp;
    int level = get_level(xp);
    int next_xp = get_xp_for_level(level);
    int last_xp = get_xp_for_level(level - 1);

    draw_load(xp - last_xp,  next_xp - last_xp, game->window);
    draw_element(game->window, game->scenes[MENU_PLAYER].elements[2]);
    draw_text(format("%d / %d", xp - last_xp, next_xp - last_xp),
            game->settings->font, (sfVector3f){750, 850, 60}, game->window);
    draw_text(inttochar(level),
            game->settings->font, (sfVector3f){340, 840, 80}, game->window);
    draw_text(inttochar(level + 1),
            game->settings->font, (sfVector3f){1470, 840, 80}, game->window);
}
