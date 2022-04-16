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
    while (str[i] != ',' && str[i++] != '\n');
    str[i] = '\0';
    return str;
}

char *coat(void)
{
    char *coat = malloc(sizeof(char) * 2);
    coat[0] = '"';
    coat[1] = '\0';
    return (coat);
}

char *parser(char *file, char *var)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *variable = conc("    ",conc(coat(),
                                    conc(var, conc(coat(), conc(":", " ")))));

    if (fd == NULL){
        my_printf("Can not open '%s' (Parsing failed)\n", file);
        free(variable);
        return NULL;
    }
    while ((read = getline(&line, &len, fd)) != -1) {
        if (my_strncmp(line, variable, my_strlen(variable)) == 0) {
            line = get_value(line, variable);
            fclose(fd);
            return line;
        }
    }
    fclose(fd);
    free(line);
    free(variable);
    return NULL;
}


void fill_file(char *file, char *buffer)
{
    int fd = open(file, O_WRONLY);
    buffer[my_strlen(buffer)] = '\0';
    write(fd, buffer, my_strlen(buffer));
    close(fd);
}

void update_file(char *file, char *var, char *value)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *buffer = "\0";
    char *variable = conc("    ",conc(coat(),
                                    conc(var, conc(coat(), conc(":", " ")))));
    if (fd == NULL) {
        my_printf("Can not open '%s' (Update failed)\n", file);
        return;
    }
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
    fill_file(file, buffer);
}