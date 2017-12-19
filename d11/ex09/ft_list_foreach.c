#include "ft_list.h"

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *elem;
	elem = begin_list;
	while (elem != 0)
	{
		(*f)(elem->data);
		elem = elem->next;
	}
}