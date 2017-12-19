
int ft_count_if(char **tab, int(*f)(char*))
{
	int i;
	int count;
	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if ( (*f)(tab[i]) == 1)
			count++;
		i++;
	}
	return(count);
}


