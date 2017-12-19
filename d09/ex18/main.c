#include <stdio.h>

char *ft_join(char **tab, char *sep);

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



int main ()
{
    int i;
    char **tab;
    char sep[1]=";";

    tab = malloc(sizeof(char*) * 4);
    tab[0] = malloc(sizeof(char) * 40);
    tab[1] = malloc(sizeof(char) * 40);
    tab[2] = malloc(sizeof(char) * 40);
    tab[3] = 0;
    ft_strcpy(tab[0], "s1");
    ft_strcpy(tab[1], "s2");
    ft_strcpy(tab[2], "s3");


    printf("Le mot concaténé: %s\n", ft_join(tab, sep));

    return 0;
}