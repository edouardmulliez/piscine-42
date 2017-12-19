#include <stdio.h>
#include "ft_list.h"

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
int ft_strcmp(char* s1, char* s2);

t_list *ft_list_push_params(int ac, char **av);

// to be used with at least 4 arguments

int main(int argc, char *argv[])
{
	t_list *begin_list1;
	t_list *begin_list2;
	
	begin_list1 = ft_list_push_params(3, argv+1);
	if (argc <= 4)
	{
		printf("Program to be used with to be used with at least 4 arguments. \n");
		return(0);
	}
	begin_list2 = ft_list_push_params(argc-4, argv+4);

	ft_sorted_list_merge(&begin_list1, begin_list2, &ft_strcmp);

	while (begin_list1 != 0)
	{
		printf("Word: %s\n", (char*)(begin_list1->data));
		begin_list1 = begin_list1->next;
	}

	return(0);
}