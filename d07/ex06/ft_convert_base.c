#include <stdlib.h>


int ft_strlen(char *str)
{
    int i;
    i = 0;
	while (str[i] != '\0')
		i++;
    return(i);
}

/*
** find biggest base^p divider for n. If base_len=10, and n=2347, then biggest_divider = 1000 and power[0] = 3.
*/
int find_biggest_divider(int power[], int n, int base_len)
{
    int divider;
	int i;
    divider = 1;
	i = 0;
    while (divider*base_len < n)
	{
		divider *= base_len;
		i++;
	}
	power[0] = i;
    return(divider);
}

int ft_atoi_base(char *str, char *base)
{
    int base_len;
    int str_len;
    int result;
    int j;
    int mul;
    base_len = ft_strlen(base);
    str_len = ft_strlen(str);
    result = 0;
    mul = 1;
    while (str_len > 0 && base_len > 1)
    {
        j = 0;
        while (base[j] != '\0')
        {
            if (str[str_len-1] == base[j])
                result += j * mul;
            j++;
        }
        mul *= base_len;
        str_len--;
    }
    return(result);
}

char *ft_putnbr_base(int nbr, char *base)
{
    int div;
    int power[1];
	int base_len;
	char *result;
	int i;
	
    base_len = ft_strlen(base);
    div = find_biggest_divider(power, nbr, base_len);
	result = (char*)malloc(sizeof(char)*(power[0] + 2));	
    i = 0;
	while (div > 0)
    {
        result[i] = base[nbr/div];
		nbr -= (nbr/div) * div;
        div /= base_len;
		i++;
    }
	result[i] = '\0';
	return(result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i;
	char *result;
	i = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(i, base_to);
	return(result);
}
