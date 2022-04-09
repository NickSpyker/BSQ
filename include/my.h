/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
** File description:
** my.h
*/

#ifndef MYLIB
    #define MYLIB
int my_getnbr(char *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_swap(char **a, char **b);
char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
int verif(int argc, char *argv[]);
void verif_format(char *buffer);
typedef struct data
{
    int size;
    char **map;
    int nb_rows;
    int nb_cols;
    int max_size;
    int max_size_loc_r;
    int max_size_loc_c;
} data_t ;
typedef struct loc
{
    int row;
    int col;
} loc_t;
void bsq(data_t *data);
void print_map(data_t *data);
#endif
