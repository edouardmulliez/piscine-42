#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av)
{
	int i;
	t_list *begin_list;
	t_list *elem;
	begin_list = ft_create_elem(av[0]);
	elem = begin_list;
	i = 1;
	while (i < ac)
	{
		elem->next = ft_create_elem(av[i]);
		elem = elem->next;
		i++;
	}
	return(begin_list);
}


