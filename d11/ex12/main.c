#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
int ft_strcmp(char* s1, char* s2);


int main(int argc, char *argv[])
{
	t_list *begin_list;
	begin_list = ft_list_push_params(argc-1, argv+1);

	ft_list_remove_if(&begin_list, "aa", &ft_strcmp);

	while (begin_list != 0)
	{
		printf("Word: %s\n", (char*)(begin_list->data));
		begin_list = begin_list->next;
	}

	return(0);
}