/*
** EPITECH PROJECT, 2021
** move.c
** File description:
** move.c
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

char **left_management(char **map, v_var *a, char **saved_map)
{
    if (map[a->y][a->x - 1] != '#' && map[a->y][a->x - 1] != 'X') {
        map[a->y][a->x - 1] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (map[a->y][a->x - 1] == 'X' && map[a->y][a->x - 2] != '#' &&
        map[a->y][a->x - 2] != 'X') {
        map[a->y][a->x - 2] = 'X';
        map[a->y][a->x - 1] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (saved_map[a->y][a->x] == 'O' && map[a->y][a->x - 1] != '#' &&
        map[a->y][a->x - 1] != 'X')
        map[a->y][a->x] = 'O';
    return (map);
}

char **right_management(char **map, v_var *a, char **saved_map)
{
    if (map[a->y][a->x + 1] != '#' && map[a->y][a->x + 1] != 'X') {
        map[a->y][a->x + 1] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (map[a->y][a->x + 1] == 'X' && map[a->y][a->x + 2] != '#' &&
        map[a->y][a->x + 2] != 'X') {
        map[a->y][a->x + 2] = 'X';
        map[a->y][a->x + 1] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (saved_map[a->y][a->x] == 'O' && map[a->y][a->x + 1] != '#' &&
        map[a->y][a->x + 1] != 'X')
        map[a->y][a->x] = 'O';
    return (map);
}

char **down_management(char **map, v_var *a, char **saved_map)
{
    if (map[a->y + 1][a->x] != '#' && map[a->y + 1][a->x] != 'X') {
        map[a->y + 1][a->x] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (map[a->y + 1][a->x] == 'X' && map[a->y + 2][a->x] != '#' &&
        map[a->y + 2][a->x] != 'X') {
        map[a->y + 2][a->x] = 'X';
        map[a->y + 1][a->x] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (saved_map[a->y][a->x] == 'O' && map[a->y + 1][a->x] != '#' &&
        map[a->y + 1][a->x] != 'X')
        map[a->y][a->x] = 'O';
    return (map);
}

char **up_management(char **map, v_var *a, char **saved_map)
{
    if (map[a->y - 1][a->x] != '#' && map[a->y - 1][a->x] != 'X') {
        map[a->y - 1][a->x] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (map[a->y - 1][a->x] == 'X' && map[a->y - 2][a->x] != '#' &&
        map[a->y - 2][a->x] != 'X') {
        map[a->y - 2][a->x] = 'X';
        map[a->y - 1][a->x] = 'P';
        map[a->y][a->x] = ' ';
    }
    if (saved_map[a->y][a->x] == 'O' && map[a->y - 1][a->x] != '#' &&
        map[a->y - 1][a->x] != 'X')
        map[a->y][a->x] = 'O';
    return (map);
}

void find_p(v_var *a, char **map)
{
    a->y = 0;
    a->x = 0;

    for (int i = 0; i != a->nb_rows; i++)
        for (int j = 0; map[i][j] != '\n'; j++)
            if (map[i][j] == 'P') {
                a->y = i;
                a->x = j;
            }
}
