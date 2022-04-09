/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nicolas.spijkerman
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int result = 0;
    int sign = 1;

    for (int i = 0; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            sign *= -1;
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] > 47 && str[i] < 58) {
            result *= 10;
            result += str[i] - 48;
        } else
            return result * sign;
    }
    return result * sign;
}
