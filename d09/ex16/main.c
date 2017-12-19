#include <stdio.h>

unsigned int ft_active_bits(int value);

int main()
{
	int value;
	value = 15;
	printf("Active bits in %d: %d \n", value, ft_active_bits(value));
	return(0);
}