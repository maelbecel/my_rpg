/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#include <stdio.h>
#include <stdlib.h>

static int is_alpha(char c)
{
    if (c != ' ')
        return 1;
    return 0;
}

static int count_words(char *str)
{
    int word = 0;
    int i = 0;
    int nb_words = 0;

    while (str[i]) {
        if (word == 0 && is_alpha(str[i]) == 1) {
            word = 1;
            nb_words = nb_words + 1;
        }
        if (word == 1 && is_alpha(str[i]) == 0)
            word = 0;
        i++;
    }
    return nb_words;
}

static void	dup_string(char *new_str, char *str, int begin, int end)
{
    int i = 0;

    while (begin <= end) {
        new_str[i] = str[begin];
        begin++;
        i++;
    }
    new_str[i] = '\0';
}

static void	fill(char **tab, char *str, int nb_words)
{
    int i = 0;
    int begin = 0;
    int word_cur = 0;

    while (word_cur < nb_words) {
        while (str[i] && is_alpha(str[i]) == 0)
            i++;
        begin = i;
        while (str[i] && is_alpha(str[i]) == 1)
            i++;
        tab[word_cur] = (char *)malloc(sizeof(char) * ((i - 1) - begin + 2));
        dup_string(tab[word_cur], str, begin, i - 1);
        i++;
        word_cur++;
    }
}

char **my_str_to_word_array(char *str)
{
    int nb_words;
    char **tab;

    nb_words = count_words(str);
    tab = (char **)malloc(sizeof(char *) * (nb_words + 1));
    fill(tab, str, nb_words);
    tab[nb_words] = NULL;
    return (tab);
}
