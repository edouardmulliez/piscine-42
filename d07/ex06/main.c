#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	printf("345 en binaire: %s \n", ft_convert_base("345", "0123456789", "01"));
	printf("345 en hexa: %s \n", ft_convert_base("345", "0123456789", "0123456789ABCDEF"));
		
	
	
	return(0);
}