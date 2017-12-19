#include "ft_list.h"

t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list != 0 && (*cmp)(begin_list->data, data_ref) != 0)
		begin_list = begin_list->next;
	return(begin_list);
}
