#include <stdlib.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
	t_list *rst;
	rst = malloc(sizeof(t_list));
	(*rst).data = data;
	(*rst).next = 0;
	return(rst);
}

