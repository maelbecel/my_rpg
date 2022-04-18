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

char *get_line_pars(FILE *fd, char *variable)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

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

char *parser(char *file, char *var)
{
    FILE *fd = fopen(file, "r");
    char *variable = conc("    ", conc(coat(),
                                    conc(var, conc(coat(), conc(":", " ")))));

    if (fd == NULL){
        my_printf("Can not open '%s' (Parsing failed)\n", file);
        free(variable);
        return NULL;
    }
    return get_line_pars(fd, variable);
}
