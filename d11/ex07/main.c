#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);

int main(int argc, char *argv[])
{
	t_list *begin_list;
	t_list *elem;
	char *ptr;

	begin_list = ft_list_push_params(argc, argv);
	elem = begin_list;
	do
	{
		ptr = elem->data;
		printf("elem->data: %s\n", ptr);
		elem = elem->next;
	} while (elem != 0);

	elem = ft_list_at(begin_list, 3);
	if (elem != 0)
	{
		ptr = elem->data;
		printf("Element n1: %s", ptr);
	}
	
	return(0);
}