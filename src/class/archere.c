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
    if (update_file(file, "class", format("\"%s\"", "archere")) == 1)
        return EXIT_FAILURE;
    if (update_file(file, "new", "0") == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "inventory", format("[\"%s\"]", "bow")) == 1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int update_all_file(game_t *game, char *file)
{
    char *health = parser(ARCHERE, "health");
    char *strength = parser(ARCHERE, "strength");
    char *speed = parser(ARCHERE, "speed");
    char *defense = parser(ARCHERE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/archere.json");
        return EXIT_FAILURE;
    }
    if (update_file(file, "health", health) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return check_file_re(file, strength, speed, defense);
}

int archere(game_t *game, ...)
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
                                    sfTexture_createFromFile(ARCHER_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
    return EXIT_SUCCESS;
}

int draw_archere_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser(ARCHERE, "health");
    char *strength = parser(ARCHERE, "strength");
    char *speed = parser(ARCHERE, "speed");
    char *defense = parser(ARCHERE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/archere.json");
        return EXIT_FAILURE;
    }
    draw_text("ARCHER", font, (sfVector3f){850, 240, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){850, 320, 30},
                                                                    window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){850, 360, 30},
                                                                    window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){850, 400, 30},
                                                                    window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){850, 440, 30},
                                                                    window);
    return EXIT_SUCCESS;
}
