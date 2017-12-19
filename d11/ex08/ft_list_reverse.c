#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
	t_list *previous_elem;
	t_list *elem;
	t_list *next_elem;

	previous_elem = 0;
	elem = *begin_list;

	while(elem != 0)
	{
		next_elem = elem->next;
		elem->next = previous_elem;
		previous_elem = elem;
		elem = next_elem;
	}
	*begin_list = previous_elem;
}