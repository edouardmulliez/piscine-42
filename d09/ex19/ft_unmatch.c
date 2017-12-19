
/*
** Count occurences of nb in tab
*/
int count_in_tab(int nb, int *tab, int length)
{
	int i;
	int count;
	i = 0;
	count = 0;
	while(i < length)
	{
		if (tab[i] == nb)
			count++;
		i++;
	}
	return(count);
}

int ft_unmatch(int *tab, int length)
{
	int i;
	i = 0;
	while (i < length)
	{
		if ((count_in_tab(tab[i], tab, length) % 2) != 0)
			return(tab[i]);
		i++;
	}
	return(-1);
}


