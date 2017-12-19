
int ft_atoi(char *str)
{
	int nb;
	nb = 0;
	while (str[0] != '\0' && str[0] >= '0' && str[0] <='9')
	{
		nb *= 10;
		nb += str[0] - '0';
		str++;
	}
	return(nb);
}

