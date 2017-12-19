#include <stdio.h>

int ft_max(int *tab, int length);

int main()
{
	int tab[5] = {2,4,1,6,-24};
	printf("Max of tab: %d", ft_max(tab, 5));
}