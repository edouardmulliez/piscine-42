
#include <stdio.h> 

int make_double(int a)
{
	return(2*a);
}

int *ft_map(int *tab, int length, int(*f)(int));

int  main()
{
	int tab[4] = {1,2,3,4};
	int *result;
	int i;
	result = ft_map(tab, 4, &make_double);
	for(i=0; i<4; i++)
		printf("%d ", result[i]);
	return(0);
}