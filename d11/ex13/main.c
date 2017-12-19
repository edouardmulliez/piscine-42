#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);

int main(int argc, char *argv[])
{
	t_list *list1;
	t_list *list2;
	t_list *begin_list;

	list1 = ft_list_push_params(argc-1, argv+1);
	list2 = ft_list_push_params(argc, argv);
	ft_list_merge(&list1, list2);

	begin_list = list1;
	while (begin_list != 0)
	{
		printf("Word: %s\n", (char*)(begin_list->data));
		begin_list = begin_list->next;
	}

	return(0);
}