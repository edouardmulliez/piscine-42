#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
void ft_list_foreach(t_list *begin_list, void (*f)(void *));

void putstr(void *str)
{
	char *str2;
	str2 = str;
	printf("Word: %s \n", str2);
}

int main(int argc, char *argv[])
{
	t_list *begin_list;
	begin_list = ft_list_push_params(argc, argv);
	ft_list_foreach(begin_list, &putstr);
	return(0);
}