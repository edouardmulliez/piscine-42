#ifndef __EVAL_EXPR_H__
#define __EVAL_EXPR_H__

void ft_putchar(char c);
void ft_putnbr(int nb);
int ft_strlen(char *str);
int char_in_str(char *str, char c);

int find_sep_index(char *str, char *sep, int start, int end);
void find_par_index(char *str, int pos[2], int start, int end);
void find_nb_index(char *str, int pos[2], int start, int end);

int do_op(int a, int b, char c);
int ft_atoi(char *str, int start, int end);
int eval_start_end(char *str, int start, int end);
int eval_expr(char *str);

#endif