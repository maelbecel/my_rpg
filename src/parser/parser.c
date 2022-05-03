/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

char *get_value(char *line, char *var)
{
    int i = 0;
    char *str = line + my_strlen(var);

    while (str[i++] != '\n');
    str[i - 1] = '\0';
    if (str[i - 2] == ',')
        str[i - 2] = '\0';
    return str;
}

char *coat(void)
{
    char *coat = malloc(sizeof(char) * 2);

    if (!coat)
        return NULL;
    coat[0] = '"';
    coat[1] = '\0';
    return (coat);
}

char *get_line_pars(FILE *fd, char *variable)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (!variable) {
        fclose(fd);
        return NULL;
    }
    while ((read = getline(&line, &len, fd)) != -1) {
        if (my_strncmp(line, variable, my_strlen(variable)) == 0) {
            line = get_value(line, variable);
            free(variable);
            fclose(fd);
            return line;
        }
    }
    fclose(fd);
    free(line);
    free(variable);
    return NULL;
}

char *parser(char *file, char *var)
{
    FILE *fd = fopen(file, "r");
    sfFont *font = sfFont_createFromFile(BASIC_FONT);
    char *variable = NULL;

    if (!font) {
        my_put_error(conc("Error: Failed to load the font %s.\n", BASIC_FONT));
        return NULL;
    }
    if (fd == NULL) {
        popup(font, format("Error:\nCan't open '%s'", file));
        sfFont_destroy(font);
        return NULL;
    }
    variable = format("    \"%s\": ", var);
    sfFont_destroy(font);
    return get_line_pars(fd, variable);
}
