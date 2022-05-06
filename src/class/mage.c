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
    char *str = format("\"%s\"", "mage");

    if (update_file(file, "strength", strength) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "speed", speed) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "defense", defense) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "class", str) == 1)
        return EXIT_FAILURE;
    free(str);
    str = format("[\"%s\"]", "baguette");
    if (update_file(file, "new", "0") == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (update_file(file, "inventory", str) == 1)
        return EXIT_FAILURE;
    free(str);
    return EXIT_SUCCESS;
}

static int update_all_file(game_t *game, char *file)
{
    char *health = parser(MAGE, "health");
    char *strength = parser(MAGE, "strength");
    char *speed = parser(MAGE, "speed");
    char *defense = parser(MAGE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/mage.json");
        return EXIT_FAILURE;
    }
    if (update_file(file, "health", health) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return check_file_re(file, strength, speed, defense);
}

int mage(game_t *game, ...)
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
                                    sfTexture_createFromFile(MAGE_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
    return EXIT_SUCCESS;
}

int draw_mage_char(sfRenderWindow *window, sfFont *font)
{
    char *health = conc("HEALTH : ", parser(MAGE, "health"));
    char *strength = conc("STRENGTH : ", parser(MAGE, "strength"));
    char *speed = conc("SPEED : ", parser(MAGE, "speed"));
    char *defense = conc("DEFENSE: ", parser(MAGE, "defense"));

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/mage.json");
        return EXIT_FAILURE;
    }
    draw_text("MAGE", font, (sfVector3f){850, 760, 40}, window);
    draw_text(health, font, (sfVector3f){850, 840, 30}, window);
    draw_text(strength, font, (sfVector3f){850, 880, 30}, window);
    draw_text(speed, font, (sfVector3f){850, 920, 30}, window);
    draw_text(defense, font, (sfVector3f){850, 960, 30}, window);
    free(health);
    free(strength);
    free(speed);
    free(defense);
    return EXIT_SUCCESS;
}
