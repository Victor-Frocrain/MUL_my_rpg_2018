/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

#define MY_ERROR (84)
#define MY_SUCCESS (0)

/* Print */
void my_putchar(char c);
void my_putstr(char *str);
void my_puterror(char *str);
void my_put_nbr(int nb);
/* Print */

/* Bool */
bool my_isneg(int nb);
bool my_strcmp(char *s1, char *s2);
bool my_strncmp(char *s1, char *s2, int x1, int x2);
bool my_str_isalpha(char *str);
bool my_str_isnum(char *str);
bool my_str_islower(char *str);
bool my_str_isupper(char *str);
bool my_str_isprintable(char *str);
bool my_is_prime(int nb);
/* Bool */

/* Calc */
int my_strlen(char *str);
int my_getnbr(char *str);
int my_power(int nb, int power);
int my_square_root(int nb);
/* Calc */

/* Manage char * */
char *my_realloc(char *str, int nb);
char *my_strcpy(char *src);
char *my_strncpy(char *str, int x1, int x2);
char *my_revstr(char *str);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *str, char *src);
char *my_strncat(char *str, char *src, int x1, int x2);
char *my_strdup(char *str);
char *my_memset(char c, int nb);
char **my_str_to_array(char *str);
/* Manage char * */

/* Unit test */
void redirect_all_std(void);
/* Unit test */

#endif /* MY_H_ */
