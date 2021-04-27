/*
** EPITECH PROJECT, 2021
** move_management.c
** File description:
** move_management.c
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

char **move_management(int key, char **map, v_var *a, char **saved_map)
{
    find_p(a, map);
    if (key == KEY_RIGHT)
        map = right_management(map, a, saved_map);
    if (key == KEY_LEFT)
        map = left_management(map, a, saved_map);
    if (key == KEY_UP)
        map = up_management(map, a, saved_map);
    if (key == KEY_DOWN)
        map = down_management(map, a, saved_map);
    return (map);
}
