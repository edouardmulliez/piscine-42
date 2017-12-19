#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *previous_elem;
	t_list *elem;
	previous_elem = 0;
	elem = *begin_list;

	while (elem != 0)
	{
		if ((cmp(elem->data, data_ref) == 0) && previous_elem == 0)
		{
			*begin_list = elem->next;
			free(elem);
			elem = *begin_list;
		}
		else if ((cmp(elem->data, data_ref) == 0) && previous_elem != 0)
		{
			previous_elem->next = elem->next;
			free(elem);
			elem = previous_elem->next;
		}
		else
		{
			previous_elem = elem;
			elem = elem->next;
		}
	}
}