/*
** EPITECH PROJECT, 2022
** getnbr
** File description:
** lib
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 0;
    int res = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            sign = sign * (-1);
        i++;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        res = res * 10;
        res = res + str[i] - 48;
        i++;
    }
    if (sign == -1)
        res = res * (sign);
    return (res);
}
