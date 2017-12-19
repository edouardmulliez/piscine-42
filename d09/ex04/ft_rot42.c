#include <stdio.h>

int main()
{
	int i;
	char c;
	i = 0;
	c = 'a';
	while (i < 100)
	{
		printf("Le %de charactere: %c \n", i, c);
		c--;
		i++;
	}
	return(0);
}