/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void update_all_file(game_t *game, char *file)
{
    char *health = parser(MAGE, "health");
    char *strength = parser(MAGE, "strength");
    char *speed = parser(MAGE, "speed");
    char *defense = parser(MAGE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/mage.json");
        return;
    }
    update_file(file, "health", health);
    update_file(file, "strength", strength);
    update_file(file, "speed", speed);
    update_file(file, "defense", defense);
    update_file(file, "class", conc(coat(), conc("mage", coat())));
    update_file(file, "new", "0");
    update_file(file, "inventory", conc("[",
                        conc(coat(), conc("baguette" ,conc(coat(), "]")))));
}

void mage(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));

    update_all_file(game, file);
    reset(game);
    game->scenes->page = GAME;
    sfTexture_destroy(game->scenes[GAME].elements[2]->texture);
    game->scenes[GAME].elements[2]->texture =
                                    sfTexture_createFromFile(MAGE_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
}

void draw_mage_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser(MAGE, "health");
    char *strength = parser(MAGE, "strength");
    char *speed = parser(MAGE, "speed");
    char *defense = parser(MAGE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/mage.json");
        return;
    }
    draw_text("MAGE", font, (sfVector3f){850, 760, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){850, 840, 30},
                                                                    window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){850, 880, 30},
                                                                    window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){850, 920, 30},
                                                                    window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){850, 960, 30},
                                                                    window);
}
