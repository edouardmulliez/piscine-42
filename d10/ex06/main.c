
#include "header.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	t_op_function func_tab[] = {add, sub, mul, div, mod};
	char *op = "+-*/%";
	int i;	
	i = 0;
	if (argc != 4)
		return(0);
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
		return(throw_div_error());
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
		return(throw_mod_error());
	i = 0;
	while (op[i] != '\0')
	{
		if (op[i] == argv[2][0])
		{
			ft_putnbr(func_tab[i](ft_atoi(argv[1]), ft_atoi(argv[3])));
			return(0);
		}
		i++;
	}
	ft_putnbr(0);
	return(0);
}