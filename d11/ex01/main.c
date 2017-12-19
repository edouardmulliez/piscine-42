#include "ft_list.h"
#include <stdio.h>

void ft_list_push_back(t_list **begin_list, void *data);

int main()
{
	int a = 1;
	int b = 2;
	int *ptr;
	t_list *l1;
	l1 = ft_create_elem(&a);
	ft_list_push_back(&l1, &b);

	ptr = (*((*l1).next)).data;
	printf("l1.data: %d \n", *ptr);
	return(0);
}