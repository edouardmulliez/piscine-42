

#include "header.h"

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

void ft_putnbr(int nbr)
{
    int div;
    div = 1;
    if (nbr < 0)
    {
    	ft_putchar('-');
    	nbr = -nbr;
    }
	while (div * 10 <= nbr)
		div *= 10;
    while (div > 0)
    {
        ft_putchar('0' + nbr/div);
        nbr -= (nbr/div) * div;
        div /= 10;
    }
	ft_putchar('\n');
}