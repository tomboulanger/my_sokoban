/*
** EPITECH PROJECT, 2021
** cols.c
** File description:
** col
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

int nb_rows(char *buffer)
{
    int x = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            x++;
    return (x);
}

char **fill_tab(char **tab, char *buffer)
{
    int i = 0;
    int j = 0;
    int z = 0;

    while (buffer[z] != '\0') {
        if (buffer[z] == '\n') {
            tab[i][j] = buffer[z];
            i++;
            j = 0;
        }
        else {
            tab[i][j] = buffer[z];
            j++;
        }
        z++;
    }
    return (tab);
}

char **malloc_2d_array(v_var *a)
{
    char **arr = NULL;
    int i = 0;

    arr = malloc(sizeof(char *) * a->nb_rows + 1);
    for (i = 0; i != a->nb_rows; i++)
        arr[i] = malloc(sizeof(char) * a->nb_cols + 1);
    return (arr);
}

int bigger_line(int x, int y)
{
    if (y > x)
        x = y;
    return (x);
}

int nb_cols(char *buffer)
{
    int i = 0;
    int x = 0;
    int y = 0;

    for (i = 0; buffer[i] != '\n'; i++)
        x++;
    i++;
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n') {
            x = bigger_line(x, y);
            y = 0;
            i++;
        }
        y++;
        i++;
    }
    return (x);
}