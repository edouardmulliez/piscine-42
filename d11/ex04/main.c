#include "ft_list.h"
#include <stdio.h>

t_list *ft_list_last(t_list *begin_list);
void ft_list_push_back(t_list **begin_list, void *data);


int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int *ptr;
	t_list *l1;
	l1 = ft_create_elem(&a);
	ft_list_push_back(&l1, &b);
	ft_list_push_back(&l1, &c);

	l1 = ft_list_last(l1);
	ptr = l1->data;

	printf("ft_list_last(l1)->data: %d \n", *ptr);
	return(0);
}