

void ft_putchar(char c);
char **ft_split(char* str, char* charset);

void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_print_words_tables(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}


int main()
{
	char **word_tab;
	word_tab = ft_split("hello !\nWhat's your   name  \n  ? \n", " \n");
	ft_print_words_tables(word_tab);
	return(0);
}