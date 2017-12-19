
void remove_element(char **tab, int index, int length)
{
	int i;
	i = index;
	while (i < length - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
}

int ft_compact(char **tab, int length)
{
	int i;
	i = 0;
	while (i < length)
	{
		if (tab[i] == 0)
		{
			remove_element(tab, i, length);
			length--;
		}
		i++;
	}
	return(length);
}
