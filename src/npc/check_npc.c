/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static float getscale(char *text)
{
    float i = 0.6;

    for (int x = 0; text[x] != '\0'; x++)
        i = (text[x] == '\n') ? i + 0.1: i;
    return i;
}

void draw_pop_text(char *text, sfFont *font, sfRenderWindow *window)
{
    sfText *text_pop = sfText_create();
    sfVector2f pos = {1455, 70};
    element_t *pop = init_element("assets/ui/button1_pop.png",
                (sfVector2f) {1425, 20},
                (sfVector2f) {792, 206}, (sfVector2f) {0.6, getscale(text)});

    sfText_setString(text_pop, text);
    sfText_setFont(text_pop, font);
    sfText_setColor(text_pop, sfBlack);
    sfText_setCharacterSize(text_pop, 30);
    sfText_setPosition(text_pop, pos);
    draw_element(window, pop);
    sfRenderWindow_drawText(window, text_pop, NULL);
    sfText_destroy(text_pop);
    free_elements(pop);
}

static int getposition(int x)
{
    switch (x) {
        case 0:
            return (3);
        case 1:
            return (2);
        case 2:
            return (1);
        case 3:
            return (0);
    }
    return x;
}

static int get_level(int xp)
{
    int level = 1;

    for (; xp >= 500 * level * level; level++);
    return (level);
}

void check_npc(game_t *game, sfEvent *event)
{
    npc_t *npc = find_npc(game);
    int pos;
    float x = (game->scenes[GAME].elements[2]->pos.x + 10 +
                        (float)game->scenes[GAME].elements[0]->rect.left + 30);
    float y = (game->scenes[GAME].elements[2]->pos.y +
                        (float)game->scenes[GAME].elements[0]->rect.top + 90);
    sfColor col = sfImage_getPixel(game->hitbox, x, y);
    sfColor dungeon = TP_DUNGEON;

    check_quest(game);
    if (npc != NULL) {
        draw_pop_text(format("Press '%s'\nto interact with %s",
                getkey(game->settings->key_action), npc->name),
                game->settings->font, game->window);
        if (event->key.code == game->settings->key_action) {
            give_quest(game, npc);
            pos = getposition(npc->elem->rect.top / npc->elem->rect.height);
            game->scenes[GAME].elements[2]->rect.top = pos *
                            game->scenes[GAME].elements[2]->rect.height;
            sfSprite_setTextureRect(game->scenes[GAME].elements[2]->sprite,
                                    game->scenes[GAME].elements[2]->rect);
            go_talk_npc(game);
        }
    }
    if (col.r == dungeon.r && col.g == dungeon.g && col.b == dungeon.b && col.a == dungeon.a && get_level(game->player->xp) < 20)
            draw_pop_text("You need to be lvl 20\nto enter the dungeon",
                                    game->settings->font, game->window);
}
