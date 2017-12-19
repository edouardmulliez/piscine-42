#include <stdio.h>
#include "ft_list.h"

int main()
{
	t_list *rst;
	int a;
	int *ptr;
	a = 1;
	rst = ft_create_elem(&a);

	ptr = (*rst).data;

	printf("rst.data: %d", *ptr);

	return(0);
}