#include "ft_stock_par.h"

#include <stdio.h>

struct s_stock_par *ft_param_to_tab(int ac, char **av);

int main(int argc, char *argv[])
{
	t_stock_par *t_s;
	t_s = ft_param_to_tab(argc, argv);

	printf("size_param: %d \n", t_s[0].size_param);
	printf("str: %s \n", t_s[0].str);
	printf("copy: %s \n", t_s[0].copy);
	printf("tab[0]: %s \n", t_s[0].tab[0]);

	return(0);
}