#include <stdio.h>
#include "ft_list.h"

t_list *ft_list_push_params(int ac, char **av);
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
int ft_strcmp(char* s1, char* s2);


int main(int argc, char *argv[])
{
	t_list *begin_list;
	begin_list = ft_list_push_params(argc, argv);
	begin_list = ft_list_find(begin_list, "aa", &ft_strcmp);

	if (begin_list != 0)
		printf("The word: %s\n", (char*)(begin_list->data));
	if (begin_list == 0)
		printf("'aa' not found");
	return(0);
}