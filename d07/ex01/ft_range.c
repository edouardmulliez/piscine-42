#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
	int diff;
	int *tab;
	
	diff = max - min;
	if (diff <= 0)
		return(NULL);
	tab = (int*)malloc(sizeof(int) * diff);
	max--;
	while (diff >= 0)
	{
		tab[diff] = min + diff;
		diff--;
	}
	return(tab);
}


int main()
{
	int *range;
	int i;
	
	range = ft_range(3,5);
	
	for (i=0; i<4; i++)
	{
		printf(" %d ", range[i]);
	}
	
	return(0);
}