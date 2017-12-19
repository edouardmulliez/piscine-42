#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());


int ft_strcmp(char* s1, char* s2);
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
	ft_list_foreach_if(begin_list, &putstr, "aa", &ft_strcmp);
	return(0);
}