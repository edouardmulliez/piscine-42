#include "ft_list.h"

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list *elem;
	elem = begin_list;
	while (elem != 0)
	{
		if ((*cmp)(elem->data, data_ref) == 0)
			(*f)(elem->data);
		elem = elem->next;
	}
}