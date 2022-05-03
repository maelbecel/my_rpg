/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void fill_file(char *file, char *buffer)
{
    int fd = open(file, O_WRONLY);
    buffer[my_strlen(buffer)] = '\0';
    write(fd, buffer, my_strlen(buffer));
    close(fd);
}

char *get_update(char *variable, FILE *fd, char *value)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *buffer = "";

    while ((read = getline(&line, &len, fd)) != -1) {
        line[read] = '\0';
        if (my_strcmp(line, "\n") == 0)
            continue;
        if (my_strcmp(line, "}\n") == 0)
            return format("%s%s", buffer, line);
        if (my_strncmp(line, variable, my_strlen(variable)) == 0) {
            buffer = format("%s%s%s%s", buffer, variable, value,
                                    (line[read - 2] == ',') ? ",\n" : "\n");
        } else
            buffer = conc(buffer, line);
    }
    free(variable);
    fclose(fd);
    return buffer;
}

int update_file(char *file, char *var, char *value)
{
    FILE *fd = fopen(file, "r");
    char *buffer;
    char *variable = format("    \"%s\": ", var);
    sfFont *font = sfFont_createFromFile(BASIC_FONT);

    if (fd == NULL) {
        popup(font, conc("Error:\nCan't open '", conc(file, "'")));
        sfFont_destroy(font);
        free(variable);
        return EXIT_FAILURE;
    }
    sfFont_destroy(font);
    buffer = get_update(variable, fd, value);
    fill_file(file, buffer);
    return EXIT_SUCCESS;
}
