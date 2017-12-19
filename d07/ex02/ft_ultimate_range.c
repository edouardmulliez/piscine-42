#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int diff;
	int *tab;
	
	diff = max - min;
	if (diff <= 0)
	{
		*range = NULL;
		return(0);
	}
	tab = malloc(sizeof(int) * (diff+3));
	while (diff >= 0)
	{
		tab[diff] = min + diff;
		diff--;
	}
	range = &tab;
	return(max-min);
}


int main()
{
	int **range;
	int len;
	int i;
	int *test;
	
	len = ft_ultimate_range(range, 3,5);
	printf("Length of range: %d \n", len);
	test = *range;
	printf("test[0]: %d \n", test[0]);
	// for (i=0; i<2; i++)
	// {
		// printf(" %d ", test[i]);
	// }
	
	return(0);
}