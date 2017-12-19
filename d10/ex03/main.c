#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

void ft_strcpy(char *dest, char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int ft_any(char **tab, int(*f)(char*));

int main()
{
	char **tab;
	tab = (char**)malloc(3 * sizeof(char*));
	tab[0] = malloc(5 * sizeof(char));
	tab[1] = malloc(5 * sizeof(char));
	ft_strcpy(tab[0], "Hello");
	ft_strcpy(tab[1], "H");
	tab[3] = 0;

	printf("Is there a 1 length str in tab? %d", ft_any(tab, &ft_strlen));
	return(0);
}