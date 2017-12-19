#include <stdlib.h>
#include "ft_list.h"

void ft_list_clear(t_list **begin_list)
{
	t_list *elem;
	t_list *next_elem;
	elem = *begin_list;
	while (elem != 0)
	{
		next_elem = elem->next;
		free(elem);
		elem = next_elem;
	}
}


