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
    char *buffer = "\0";

    while ((read = getline(&line, &len, fd)) != -1) {
        if (my_strncmp(line, variable, my_strlen(variable)) == 0) {
            buffer = conc(buffer, conc(variable, conc(value,
                                    (line[read - 2] == ',') ? ",\n" : "\n")));
        } else
            buffer = conc(buffer, line);
    }
    free(line);
    free(variable);
    fclose(fd);
    return buffer;
}

void update_file(char *file, char *var, char *value)
{
    FILE *fd = fopen(file, "r");
    char *buffer;
    char *variable = conc("    ",conc(coat(),
                                    conc(var, conc(coat(), conc(":", " ")))));
    if (fd == NULL) {
        my_printf("Can not open '%s' (Update failed)\n", file);
        return;
    }
    buffer = get_update(variable, fd, value);
    fill_file(file, buffer);
}
