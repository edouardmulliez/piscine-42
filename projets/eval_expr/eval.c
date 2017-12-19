#include "eval_expr.h"

int do_op(int a, int b, char c)
{
	if (c == '+')
		return(a + b);
	if (c == '-')
		return(a - b);
	if (c == '*')
		return(a * b);
	if (c == '/')
		return(a / b);
	if (c == '%')
		return(a % b);

	return(0);
}


int ft_atoi(char *str, int start, int end)
{
	int i;
	int nb;
	int sign;

	sign = 1;
	nb = 0;
	i = start;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && i <= end)
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	return(sign * nb);
}

int eval_start_end(char *str, int start, int end)
{
	int i;
	int pos[2];

	if (end < start)
		return(0);

	if ((i = find_sep_index(str, "+-", start, end)) != -1)
		return(do_op(eval_start_end(str, start, i-1), eval_start_end(str, i + 1, end), str[i]));
	
	if ((i = find_sep_index(str, "*%/", start, end)) != -1)
		return(do_op(eval_start_end(str, start, i-1), eval_start_end(str, i + 1, end), str[i]));
	
	find_par_index(str, pos, start, end);
	if (pos[0] != -1)
		return(eval_start_end(str, pos[0] + 1, pos[1] - 1));
	
	find_nb_index(str, pos, start, end);
	return(ft_atoi(str, pos[0], pos[1]));
}

int eval_expr(char *str)
{
	return(eval_start_end(str, 0, ft_strlen(str) - 1));
}