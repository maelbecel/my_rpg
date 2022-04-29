/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

char *str_from_json(char *file, char *var)
{
    if (parser(file, var) == NULL)
        return NULL;
    return clean_string(parser(file, var));
}

char **str_array_from_json(char *file, char *var)
{
    if (parser(file, var) == NULL)
        return NULL;
    return my_str_to_word_array(clean_string(parser(file, var)), ',');
}

int int_from_json(char *file, char *var)
{
    int value = 0;
    char *parse = NULL;

    parse = parser(file, var);
    if (parse == NULL)
        return -1;
    value = my_getnbr(parse);
    return value;
}

int *int_array_from_json(char *file, char *var, int *size)
{
    char **array = str_array_from_json(file, var);
    int *int_array;
    int i = 0;

    if (!array)
        return NULL;
    int_array = malloc(sizeof(int) * my_strarraylen(array));
    if (!int_array)
        return NULL;
    for (; array[i]; i++) {
        int_array[i] = my_getnbr(array[i]);
        free(array[i]);
    }
    if (size != NULL)
        *size = i;
    free(array);
    return int_array;
}
