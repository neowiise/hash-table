/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-miniprintf-iness.el-atouani
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putchar(char c);
char *my_strcpy(char *dest, char const *src);
int handle_char(va_list args);
int handle_int(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int mini_printf(const char *format, ...);
int my_strcmp(char const *s1, char const *s2);
#endif /* !MY_H_ */
