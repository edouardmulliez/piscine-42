#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;
	i = 0;
	t_list *elem;
	elem = begin_list;
	while (i < nbr && elem != 0)
	{
		elem = elem->next;
		i++;
	}
	return(elem);
}

