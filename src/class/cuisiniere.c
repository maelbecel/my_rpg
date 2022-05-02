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
    char *health = parser(CUISINIERE, "health");
    char *strength = parser(CUISINIERE, "strength");
    char *speed = parser(CUISINIERE, "speed");
    char *defense = parser(CUISINIERE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/archere.json");
        return;
    }
    update_file(file, "health", health);
    update_file(file, "strength", strength);
    update_file(file, "speed", speed);
    update_file(file, "defense", defense);
    update_file(file, "class", format("\"%s\"", "cuisiniere"));
    update_file(file, "new", "0");
    update_file(file, "inventory", format("[\"%s\"]", "rouleau"));
}

void cuisiniere(game_t *game, ...)
{
    char *file = format("saves/save%s.json", game->player->save);

    update_all_file(game, file);
    reset(game);
    game->scenes->page = GAME;
    sfTexture_destroy(game->scenes[GAME].elements[2]->texture);
    game->scenes[GAME].elements[2]->texture =
                                    sfTexture_createFromFile(COOKER_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
}

void draw_cuisiniere_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser(CUISINIERE, "health");
    char *strength = parser(CUISINIERE, "strength");
    char *speed = parser(CUISINIERE, "speed");
    char *defense = parser(CUISINIERE, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/cuisiniere.json");
        return;
    }
    draw_text("CHEF", font, (sfVector3f){350, 760, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){350, 840, 30},
                                                                    window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){350, 880, 30},
                                                                    window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){350, 920, 30},
                                                                    window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){350, 960, 30},
                                                                    window);
}
