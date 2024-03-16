/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (i < n) {
        while (i < n) {
            dest[i] = '\0';
            i++;
        }
    }
    return dest;
}
