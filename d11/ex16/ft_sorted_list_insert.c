#include "ft_list.h"


t_list *ft_create_elem(void *data);

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *elem;
	t_list *new_elem;	
	elem = *begin_list;
	new_elem = ft_create_elem(data);
	if (elem == 0)
	{
		*begin_list = new_elem;
		return;
	}
	if ((*cmp)(data, elem->data) < 0)
	{
		*begin_list = new_elem;
		(*begin_list)->next = elem;
		return;
	}
	while (elem->next != 0)
	{
		if ((*cmp)(data, elem->next->data) < 0)
		{
			new_elem->next = elem->next;
			elem->next = new_elem;
			return;
		}
		elem = elem->next;
	}
	elem->next = new_elem;
}