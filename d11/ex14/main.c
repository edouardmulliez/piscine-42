#include "ft_list.h"
#include <stdio.h>

void ft_list_sort(t_list **begin_list, int (*cmp)());
int ft_strcmp(char* s1, char* s2);
t_list *ft_list_push_params(int ac, char **av);



int main(int argc, char *argv[])
{
	t_list *begin_list;
	begin_list = ft_list_push_params(argc-1, argv+1);
	ft_list_sort(&begin_list, &ft_strcmp);

	while (begin_list != 0)
	{
		printf("Word: %s\n", (char*)(begin_list->data));
		begin_list = begin_list->next;
	}
	return(0);
}