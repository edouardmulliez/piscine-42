#include <stdio.h>


char **ft_split_whitespaces(char* str);

int main()
{
	int i;
	
	char **word_tab;
	word_tab = ft_split_whitespaces("hello !\nWhat's your   name  \n  ? \n");
	
	i = 0;
	while(word_tab[i])
	{
		printf("word_tab[%d]: %s\n", i, word_tab[i]);
		i++;
	}

	return(0);
}