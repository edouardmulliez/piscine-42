#include <stdlib.h>
#include "ft_stock_par.h"

#include <stdio.h>

char **ft_split_whitespaces(char *str);

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

char* ft_strcpy(char* dest, char* src){
    int i =0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	int i;
	t_stock_par *t_s;
	i = 0;
	t_s = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac+1));
	while (i < ac)
	{
		t_s[i].size_param = ft_strlen(av[i]);
		t_s[i].str = av[i];
		t_s[i].copy = (char*)malloc(sizeof(char) * t_s[i].size_param);
		ft_strcpy(t_s[i].copy, av[i]);
		t_s[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	t_s[i].str = 0;
	return(t_s);
}


