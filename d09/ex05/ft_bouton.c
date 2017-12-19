#include <stdio.h>

int ft_bouton(int i, int j, int k)
{
	if ((i<=j && j<=k) || (k<=j && j<=i))
		return(j);
	if ((j<=i && i<=k) || (k<=i && i<=j))
		return(i);
	return(k);
}


int main()
{
	printf("le milieu %d", ft_bouton(44,25,23));
	return(0);
}