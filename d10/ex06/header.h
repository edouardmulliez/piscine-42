

#ifndef FT_HEADER_H
#define FT_HEADER_H

#include <unistd.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nbr);

int ft_atoi(char *str);

int throw_mod_error();
int throw_div_error();

typedef int (*t_op_function)(int, int);

#endif