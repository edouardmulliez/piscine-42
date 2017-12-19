#include <unistd.h>

void ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void ft_puterror(char *str)
{
	int i;
	i = 0;
	
	while (str[i] != '\0')
	{
		write(2, &(str[i]), 1);
		i++;
	}
}

void ft_putnbr_error(int nb)
{
	if (nb < 0)
	{
		ft_putchar_error('-');
		nb = -nb;
	}

	if (nb > 9)
	{
		ft_putnbr_error(nb/10);
		ft_putnbr_error(nb - (nb/10) * 10);
	}
	else
	{
		ft_putchar_error('0' + nb);
	}
}
