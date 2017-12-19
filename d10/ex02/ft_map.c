#include <stdlib.h>


int *ft_map(int *tab, int length, int(*f)(int))
{
	int *result;
	int i;
	result = (int*)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		result[i] = (*f)(tab[i]);
		i++;
	}
	return(result);
}


