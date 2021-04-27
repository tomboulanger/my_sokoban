/*
** EPITECH PROJECT, 2021
** my_sokoban.h
** File description:
** my_sokoban.h
*/

#ifndef __MY_SOKOBAN_H__
#define __MY_SOKOBAN_H__

#include <ncurses.h>

typedef struct v_variable
{
    int nb_rows;
    int nb_cols;
    int x;
    int y;
    int nb_x;
    int defeat;
    int nb_o;
}v_var;

char *open_read_file(char const *filepath, v_var *a);
int nb_rows(char *buffer);
int nb_cols(char *buffer);
void find_p(v_var *a, char **map);
void close_game (v_var *a, char **map, char **saved_map, char *buffer);
void init_struct(char *buffer, v_var *a);
char **malloc_2d_array(v_var *a);
void my_popup(v_var *a, char *buffer);
char **my_sokoban(char const *filepath);
int display_array(char **array, v_var *a);
char **fill_tab(char **tab, char *buffer);
int check_map(v_var *a, char *buffer);
int error_management(int ac, char **av);
int error(char **av);
char **move_management(int input, char **map, v_var *a, char **saved_map);
char **left_management(char **map, v_var *a, char **saved_map);
char **right_management(char **map, v_var *a, char **saved_map);
char **down_management(char **map, v_var *a, char **saved_map);
char **up_management(char **map, v_var *a, char **saved_map);
void display(char **map, v_var *a);
char **create_map(char *buffer, v_var *a);
int victory(char **map, char **saved_map, v_var *a);

#endif /*__MY_SOKOBAN_H__*/
