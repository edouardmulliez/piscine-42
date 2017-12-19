
void ft_putchar(char c);

int main (int argc, char *argv[])
{
	int i;
	char *name;
	i = 0;
	name = argv[0];
	while (name[i] != '\0')
	{
		ft_putchar(name[i]);
		i++;
	}
	
	return(0);
}
