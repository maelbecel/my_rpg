/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

element_t *element_copy(element_t *element)
{
    element_t *copy = malloc(sizeof(element_t));

    copy->texture = sfTexture_copy(element->texture);
    copy->sprite = sfSprite_copy(element->sprite);
    copy->scale = element->scale;
    copy->rect = (sfIntRect){element->rect.left, element->rect.top,
                                element->rect.width, element->rect.height};
    copy->pos = element->pos;
    copy->max_sprite = element->max_sprite;
    return copy;
}

static bool colision(sfColor a, sfColor b)
{
    if (a.r == b.r && a.g == b.g && a.b == b.b)
        return true;
    return false;
}

static char *get_enemy(game_t *game)
{
    float x = (game->scenes[GAME].elements[2]->pos.x +
                        (float)game->scenes[GAME].elements[0]->rect.left + 30);
    float y = (game->scenes[GAME].elements[2]->pos.y +
                        (float)game->scenes[GAME].elements[0]->rect.top + 90);
    sfColor place = sfImage_getPixel(game->hitbox, x, y);

    if (colision(place, SPIDER))
        return my_strdup("spider");
    if (colision(place, SLIME))
        return my_strdup("slime");
    if (colision(place, TREEMAN))
        return my_strdup("treeman");
    if (colision(place, BOSS))
        return my_strdup("boss");
    return NULL;
}

static void prep_battle(game_t *game)
{
    char *type = get_enemy(game);
    if (type == NULL)
        return;
    game->enemy = create_enemy(type, game->player);
    game->scenes[GAME].elements[2]->rect.top =
                        2 * game->scenes[GAME].elements[2]->rect.height;
    game->scenes[GAME].elements[2]->rect.left = 0;
    sfSprite_setTextureRect(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->rect);
    game->scenes[BATTLE].elements[2] =
                            element_copy(game->scenes[GAME].elements[2]);
    game->scenes[BATTLE].elements[2]->pos = BATTLE_POS;
    game->scenes[BATTLE].elements[2]->scale = BATTLE_SCALE;
    sfSprite_setScale(game->scenes[BATTLE].elements[2]->sprite,
                        game->scenes[BATTLE].elements[2]->scale);
    game->scenes->page = BATTLE;
    if (my_strcmp(type, "treeman") == 0) {
        game->enemy->elem->pos.x  -= 50;
        game->enemy->elem->rect = (sfIntRect){0, 0, 150, 180};
        game->enemy->elem->scale = (sfVector2f){1.5, 1.5};
        sfSprite_setScale(game->enemy->elem->sprite,
                            game->enemy->elem->scale);
    }
    battle(game);
}

int check_enemy(game_t *game)
{
    int random = my_random();

    if (random == -1)
        return -1;
    if (random % 100 == 0) {
        prep_battle(game);
    }
    return EXIT_SUCCESS;
}
