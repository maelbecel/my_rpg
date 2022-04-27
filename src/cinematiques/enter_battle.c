/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static bool skip(sfRenderWindow *window)
{
    int key = int_from_json(SETTINGS_FILE , "skip_key");
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtKeyPressed && event.key.code == key)
            return true;
    return false;
}

static void move(sfSprite *player, sfSprite *enemy, int i)
{
    sfSprite_setPosition(player, (sfVector2f){i, 500});
    sfSprite_setPosition(enemy, (sfVector2f){1920 - i - 100, 500});
}

static void init(sfSprite *player, sfSprite *enemy, sfSprite *background)
{
    sfSprite_setTexture(background,
        sfTexture_createFromFile("assets/cinematiques/battle.png", NULL),
                                                                    sfTrue);
    sfSprite_setPosition(player, (sfVector2f){0, 500});
    sfSprite_setPosition(enemy, (sfVector2f){1820, 500});
}

static void draw(game_t *game, sfSprite *background,
                                            sfSprite *player, sfSprite *enemy)
{
    game->scenes->page = BATTLE;
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, background, NULL);
    sfRenderWindow_drawSprite(game->window, player, NULL);
    sfRenderWindow_drawSprite(game->window, enemy, NULL);
    draw_text_white(conc("Press '", conc(getkey(game->settings->key_skip),
                    "' to skip")), 60, (sfVector2f){1200, 930}, game->window);
    sfRenderWindow_display(game->window);
}

int battle(game_t *game, sfSprite *a, sfSprite *b)
{
    sfMusic *music = sfMusic_createFromFile("assets/sounds/fight.ogg");
    sfSprite *player = sfSprite_copy(a);
    sfSprite *enemy = sfSprite_copy(b);
    sfSprite *background = sfSprite_create();
    int i = 0;

    init(player, enemy, background);
    while (!skip(game->window)) {
        if (i < 840)
            i += 15;
        else {
            fight_display(music, game->window);
            break;
        }
        move(player, enemy, i);
        draw(game, background, player, enemy);
    }
    sfMusic_destroy(music);
    return EXIT_SUCCESS;
}
