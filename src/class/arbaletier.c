/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int update_all_file(game_t *game, char *file)
{
    char *health = parser(ARBALETIER, "health");
    char *strength = parser(ARBALETIER, "strength");
    char *speed = parser(ARBALETIER, "speed");
    char *defense = parser(ARBALETIER, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/arbaletier.json");
        return EXIT_FAILURE;
    }
    if (update_file(file, "health", health) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "strength", strength) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "speed", speed) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "defense", defense) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "class", format("\"%s\"", "arbaletier")) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "new", "0") == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "inventory", format("[\"%s\"]", "crossbow")) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int arbaletier(game_t *game, ...)
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
                                    sfTexture_createFromFile(CROSSBOW_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
    return EXIT_SUCCESS;
}

int draw_arbaletier_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser(ARBALETIER, "health");
    char *strength = parser(ARBALETIER, "strength");
    char *speed = parser(ARBALETIER, "speed");
    char *defense = parser(ARBALETIER, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/arbaletier.json");
        return EXIT_FAILURE;
    }
    draw_text("CROSSBOWMAN", font, (sfVector3f){260, 240, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){350, 320, 30},
                                                                    window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){350, 360, 30},
                                                                    window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){350, 400, 30},
                                                                    window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){350, 440, 30},
                                                                    window);
    return EXIT_SUCCESS;
}
