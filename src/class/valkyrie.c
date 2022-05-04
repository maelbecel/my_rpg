/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int check_file_re(char *file, char *strength,
                                                    char *speed, char *defense)
{
    if (update_file(file, "strength", strength) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "speed", speed) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "defense", defense) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "class", format("\"%s\"", "valkyrie")) == 1)
        return EXIT_FAILURE;
    if (update_file(file, "new", "0") == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "inventory", format("[\"%s\"]", "hache")) == 1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int update_all_file(game_t *game, char *file)
{
    char *health = parser(VALKYRIE, "health");
    char *strength = parser(VALKYRIE, "strength");
    char *speed = parser(VALKYRIE, "speed");
    char *defense = parser(VALKYRIE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/valkyrie.json");
        return EXIT_FAILURE;
    }
    if (update_file(file, "health", health) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return check_file_re(file, strength, speed, defense);
}

int valkyrie(game_t *game, ...)
{
    char *file = format("saves/save%s.json", game->player->save);

    if (!file)
        return EXIT_FAILURE;
    if (update_all_file(game, file) == EXIT_FAILURE)
        return EXIT_FAILURE;
    reset(game);
    game->scenes->page = GAME;
    sfTexture_destroy(game->scenes[GAME].elements[2]->texture);
    game->scenes[GAME].elements[2]->texture =
                                    sfTexture_createFromFile(VALKYRIE_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
    return EXIT_SUCCESS;
}

int draw_valkyrie_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser(VALKYRIE, "health");
    char *strength = parser(VALKYRIE, "strength");
    char *speed = parser(VALKYRIE, "speed");
    char *defense = parser(VALKYRIE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/valkyrie.json");
        return EXIT_FAILURE;
    }
    draw_text("VALKYRIE", font, (sfVector3f){1350, 760, 40}, window);
    draw_text(format("HEALTH : %s", health), font, (sfVector3f){1350, 840, 30},
                                                                    window);
    draw_text(format("STRENGTH : %s", strength), font,
                                        (sfVector3f){1350, 880, 30}, window);
    draw_text(format("SPEED : %s", speed), font, (sfVector3f){1350, 920, 30},
                                                                    window);
    draw_text(format("DEFENSE: %s", defense), font,
                                        (sfVector3f){1350, 960, 30}, window);
    return EXIT_SUCCESS;
}
