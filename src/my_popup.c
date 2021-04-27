/*
** EPITECH PROJECT, 2021
** my_popup.c
** File description:
** my_popup.c
*/

#include "../include/my.h"
#include "../include/my_sokoban.h"

void my_popup(v_var *a, char *buffer)
{
    int key;
    char **map = create_map(buffer, a);
    char **saved_map = create_map(buffer, a);

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        display(map, a);
        key = getch();
        map = move_management(key, map, a, saved_map);
        if (victory(map, saved_map, a) == -1) {
            clear();
            refresh();
            break;
        }
    }
    close_game(a, map, saved_map, buffer);
}

void display(char **map, v_var *a)
{
    for (int i = 0; i < a->nb_rows; i++)
        printw(map[i]);
}

void close_game (v_var *a, char **map, char **saved_map, char *buffer)
{
    display(map, a);
    free(buffer);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    for (int j = 0; saved_map[j] != NULL; j++)
        free(saved_map[j]);
    free(saved_map);
    refresh();
    endwin();
}

int check_map(v_var *a, char *buffer)
{
    a->nb_x = 0;
    a->nb_o = 0;
    int p = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != ' ' &&
        buffer[i] != 'P' && buffer[i] != '#' && buffer[i] != '\n')
            return (84);
        if (buffer[i] == 'X')
            a->nb_x++;
        if (buffer[i] == 'O')
            a->nb_o++;
        if (buffer[i] == 'P')
            p++;
    }
    if (p != 1)
        return (84);
    if (a->nb_o != a->nb_x)
        return (84);
    return (0);
}
