#include <stdio.h>


char **ft_split_whitespaces(char* str);
void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *));
int ft_strcmp(char* s1, char* s2);

int main()
{
	char **tab;

	tab = ft_split_whitespaces("Oh my god! Hello World");
	ft_advanced_sort_wordtab(tab, &ft_strcmp);
	int i = 0;
	while (tab[i] != 0)
	{
		printf("tab[%d]: %s \n", i, tab[i]);
		i++;
	}
}