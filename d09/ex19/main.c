#include <stdio.h>

int ft_unmatch(int *tab, int length);

int main()
{
	int tab[5] = {1,1,2,1};
	printf("La paire manquante: %d \n", ft_unmatch(tab, 5));
	return(0);
}