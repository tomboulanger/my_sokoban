/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include "../include/my_sokoban.h"
#include "../include/my.h"

char **create_map(char *buffer, v_var *a)
{
    char **map = NULL;

    map = malloc_2d_array(a);
    fill_tab(map, buffer);
    return (map);
}

int main(int ac, char **av)
{
    v_var *a = malloc(sizeof(v_var));
    char *buffer;

    if (ac != 2)
        return (84);
    if (error(av) == 84)
        return (84);
    buffer = open_read_file(av[1], a);
    if (check_map(a, buffer) == 84)
        return (84);
    my_popup(a, buffer);
    free(a);
    return (0);
}

int error(char **av)
{
    struct stat buf;
    int fd = open(av[1], O_RDONLY);

    if (stat(av[1], &buf) == -1)
        return (84);
    if (buf.st_size == 0)
        return (84);
    if (fd == -1)
        return (84);
    return (0);
}

char *open_read_file(char const *filepath, v_var *a)
{
    struct stat s;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &s);
    int size = s.st_size;
    char *buffer;

    buffer = malloc(sizeof(char *) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    a->nb_rows = nb_rows(buffer);
    a->nb_cols = nb_cols(buffer);
    return (buffer);
}
