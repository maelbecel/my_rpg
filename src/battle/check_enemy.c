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

static char *get_enemy(void)
{
    char **types = str_array_from_json(CONFIG_FILE, "enemy_list");
    char *type = types[my_random() % my_strarraylen(types)];
    return clean_string(type);
}

static void prep_battle(game_t *game)
{
    game->enemy = create_enemy(get_enemy(), game->player);
    game->scenes[GAME].elements[2]->rect.top =
                        2 * game->scenes[GAME].elements[2]->rect.height;
    game->scenes[GAME].elements[2]->rect.left = 0;
    sfSprite_setTextureRect(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->rect);
    battle(game, game->scenes[GAME].elements[2]->sprite,
                                game->enemy->elem->sprite);
    sfRenderWindow_setFramerateLimit(game->window,
                    int_from_json(CONFIG_FILE, "framerate"));
    game->scenes[BATTLE].elements[2] =
                            element_copy(game->scenes[GAME].elements[2]);
    game->scenes[BATTLE].elements[2]->pos = BATTLE_POS;
    game->scenes[BATTLE].elements[2]->scale = BATTLE_SCALE;
    sfSprite_setScale(game->scenes[BATTLE].elements[2]->sprite,
                        game->scenes[BATTLE].elements[2]->scale);
}

int check_enemy(game_t *game)
{
    int random = 0;

    if ((random = my_random()) == -1)
        return -1;
    if (random % 100 == 0) {
        prep_battle(game);
    }
    return EXIT_SUCCESS;
}
