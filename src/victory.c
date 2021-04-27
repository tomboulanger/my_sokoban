/*
** EPITECH PROJECT, 2021
** victory.c
** File description:
** victory.c
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

int victory(char **map, char **saved_map, v_var *a)
{
    int c = 0;

    for (int i = 0; i != a->nb_rows; i++)
        for (int j = 0; saved_map[i][j] != '\n'; j++)
            if (saved_map[i][j] == 'O' && map[i][j] == 'X')
                c++;
    if (c == a->nb_o)
        return (-1);
    return (0);
}
