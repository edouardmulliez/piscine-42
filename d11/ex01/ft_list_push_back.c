#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *elem;
	elem = (*begin_list);
	while (elem->next != 0)
		elem = elem->next;
	elem->next = ft_create_elem(data);
}
