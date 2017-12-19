#include "ft_stock_par.h"

void ft_putchar(char c);
void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void ft_putnbr(int nbr)
{
    int div;
    div = 1;
	while (div * 10 < nbr)
		div *= 10;
    while (div > 0)
    {
        ft_putchar('0' + nbr/div);
        nbr -= (nbr/div) * div;
        div /= 10;
    }
	ft_putchar('\n');
}

void ft_print_words_tables(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
}

void ft_show_tab(struct s_stock_par *par)
{
	int i;
	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].copy);
		ft_putnbr(par[i].size_param);
		ft_print_words_tables(par[i].tab);
		i++;
	}
}
