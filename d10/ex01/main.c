#include <stdio.h>

void ft_putnbr(int nb)
{
	printf("%d ", nb);
}

void ft_foreach(int *tab, int length, void(*f)(int));

int main()
{
	int tab[4] ={1,2,3,4};
	ft_foreach(tab, 4, &ft_putnbr);
	return(0);
}