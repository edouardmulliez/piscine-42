#include "ft_list.h"

#include <stdio.h>
#include <stdlib.h>

void ft_list_push_front(t_list **begin_list, void *data);

int main()
{
	int a = 1;
	int b = 2;
	int *ptr;
	t_list **begin_list;
	begin_list = malloc(sizeof(t_list*));
	*begin_list = ft_create_elem(&a);
	ft_list_push_front(begin_list, &b);

	// ptr = (*begin_list)->next->data;
	ptr = (*begin_list)->data;
	printf("l1.data: %d \n", *ptr);
	return(0);
}