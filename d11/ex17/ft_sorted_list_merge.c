#include "ft_list.h"

/*
** Insert begin_list2 at the beginning of begin_list1. Returns begin_list2->next.
*/
t_list *insert_at_beginning(t_list **begin_list1, t_list *begin_list2)
{
	t_list *elem;
	elem = begin_list2->next;
	begin_list2->next = *begin_list1;
	*begin_list1 = begin_list2;
	return(elem);
}

/*
** Insert first elem of list2 in sorted list list1 
** (does not deal with cases where list1 should be inseted in first position). 
** Returns list2->next.
*/
t_list *insert_sorted(t_list *list1, t_list *list2, int (*cmp)())
{
	t_list *list2_next;
	list2_next = list2->next;
	while (list1->next != 0 && (*cmp)(list2->data, list1->next->data) > 0)
		list1 = list1->next;
	list2->next = list1->next;
	list1->next = list2;
	return(list2_next);
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	if (*begin_list1 == 0)
		*begin_list1 = begin_list2;
	while (begin_list2 != 0 && (*cmp)(begin_list2->data, (*begin_list1)->data) < 0)
		begin_list2 = insert_at_beginning(begin_list1, begin_list2);
	while (begin_list2 != 0)
		begin_list2 = insert_sorted(*begin_list1, begin_list2, cmp);
}






