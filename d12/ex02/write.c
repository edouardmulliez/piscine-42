#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void ft_put_header(char *str)
{
	ft_putstr("==> ");
	ft_putstr(str);
	ft_putstr(" <==\n");
}