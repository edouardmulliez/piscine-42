#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
void ft_list_clear(t_list **begin_list);

int main(int argc, char *argv[])
{
	t_list *begin_list;
	char *ptr;

	begin_list = ft_list_push_params(argc, argv);
	do
	{
		ptr = begin_list->data;
		printf("begin_list->data: %s\n", ptr);
		begin_list = begin_list->next;
	} while (begin_list != 0);

	ft_list_clear(&begin_list);
	
	return(0);
}