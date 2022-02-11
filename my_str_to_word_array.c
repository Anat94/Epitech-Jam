/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** my_str_to_word_array
*/

#include "gorilla.h"

int is_sep(char c, char *sep)
{
    for (int i = 0; sep[i]; i++) {
        if (c == sep[i])
            return 1;
    }
    return 0;
}

int count_word(char *str, char *sep)
{
    int i = 0;
    int count = 0;
    while (str[i]) {
        while (is_sep(str[i], sep) == 0 && str[i])
            i++;
        while (is_sep(str[i], sep) == 1 && str[i])
            i++;
        count += 1;
    }
    return count;
}

int fill_tab(char **tab, char *str,char *sep, int j)
{
    int start = 0;
    int size = 0;
    int index = 0;
    while (is_sep(str[j], sep) == 1 && str[j])
        j++;
    start = j;
    while (is_sep(str[start], sep) == 0 && str[start])
        start++;
    size = start - j;
    if (!(tab[0] = malloc(sizeof(char) * (size + 1))))
        return 0;
    while (index < size)
        tab[0][index++] = str[j++]; 
    tab[0][size] = '\0';
    index = 0;
    return j;
}

char **my_str_to_word_array(char *str, char *sep)
{
    int i = 0;
    int j = 0;
    int nb_word = count_word(str, sep);
    char **tab;
    if (!(tab = malloc(sizeof(char *) * (nb_word + 1))))
        return NULL;
    while (i < nb_word) {
        j = fill_tab(&tab[i], str, sep, j);
        i++;
    }
    tab[nb_word] = NULL;
    return tab;
}
