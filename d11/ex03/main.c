#include "ft_list.h"
#include <stdio.h>

int ft_list_size(t_list *begin_list);
void ft_list_push_back(t_list **begin_list, void *data);


int main()
{
	int a = 1;
	int b = 2;
	t_list *l1;
	l1 = ft_create_elem(&a);
	ft_list_push_back(&l1, &b);
	ft_list_push_back(&l1, &b);

	printf("list size: %d \n", ft_list_size(l1));
	return(0);
}