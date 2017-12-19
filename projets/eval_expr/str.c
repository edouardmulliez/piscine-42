
int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int char_in_str(char *str, char c)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return(1);
		i++;
	}
	return(0);
}
