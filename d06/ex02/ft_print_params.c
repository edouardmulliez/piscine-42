
void ft_putchar(char c);

int main (int argc, char *argv[])
{
	int i;
	int j;
	char *parameter;
	i = 1;
	while (i < argc)
	{
		parameter = argv[i];
		j = 0;
		while (parameter[j] != '\0')
		{
			ft_putchar(parameter[j]);
			j++;
		}
		i++;
		if (i < argc)
			ft_putchar('\n');		
	}	
	return(0);
}
