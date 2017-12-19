#include "ft_list.h"

/*
** Exchange previous_elem->next and previous_elem->next->next in list.
*/
int switch_elem(t_list *previous_elem)
{
	t_list *elem;
	t_list *next_elem;
	elem = previous_elem->next;
	next_elem = elem->next;
	
	previous_elem->next = elem->next;
	elem->next = next_elem->next;
	next_elem->next = elem;
	return(0);
}

/*
** Exchange first two elements of list
*/
int switch_first(t_list **begin_list)
{
	t_list *elem;
	t_list *next_elem;
	
	elem = *begin_list;
	next_elem = elem->next;
	elem->next = next_elem->next;
	next_elem->next = elem;
	*begin_list = next_elem;
	return(0);
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *elem;
	t_list *previous_elem;
	int is_sorted;

	elem = *begin_list;
	if (elem == 0)
		return;
	if (elem->next == 0)
		return;
	is_sorted = 0;
	while (is_sorted == 0)
	{
		is_sorted = 1;
		previous_elem = *begin_list;
		if ((*cmp)(previous_elem->data, previous_elem->next->data) > 0)
			is_sorted = switch_first(begin_list);
		previous_elem = *begin_list;
		while(previous_elem->next->next != 0)
		{
			if ((*cmp)(previous_elem->next->data, previous_elem->next->next->data) > 0)
				is_sorted = switch_elem(previous_elem);
			previous_elem = previous_elem->next;
		}
	}
}






