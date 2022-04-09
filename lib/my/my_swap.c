/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nicolas.spijkerman
** File description:
** my_swap.c
*/

void my_swap(char **a, char **b)
{
    char *temp = *a;

    *a = *b;
    *b = temp;
}
