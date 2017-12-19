#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
void ft_list_reverse(t_list **begin_list);

int main(int argc, char *argv[])
{
	t_list *begin_list;
	t_list *elem;
	char *ptr;

	begin_list = ft_list_push_params(argc, argv);
	ft_list_reverse(&begin_list);
	elem = begin_list;
	while (elem != 0)
	{
		ptr = elem->data;
		printf("elem->data: %s\n", ptr);
		elem = elem->next;
	}

	return(0);
}