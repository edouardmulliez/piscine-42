
#include <stdio.h>


int compare(int a, int b)
{
	return(a-b);
}

int ft_is_sort(int *tab, int length, int(*f)(int, int));

int main()
{
	int tab[4] = {1,3,3,5};
	printf("Tab is sorted: %d", ft_is_sort(tab, 4, &compare));
	return(0);
}