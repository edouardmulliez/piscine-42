#include <stdio.h>


char **ft_split_whitespaces(char* str);
void ft_sort_wordtab(char **tab);

int main()
{
	char **tab;

	tab = ft_split_whitespaces("Oh my god! Hello World");
	ft_sort_wordtab(tab);
	int i = 0;
	while (tab[i] != 0)
	{
		printf("tab[%d]: %s \n", i, tab[i]);
		i++;
	}
}