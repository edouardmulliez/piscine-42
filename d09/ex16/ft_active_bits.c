
unsigned int ft_active_bits(int value)
{
	int div;
	int count;
	int sign;
	div = 1;
	count = 0;
	sign = 1;
	if (value < 0)
	{
		value = -value;
		sign = -1;
	}
	while (div < value)
		div *= 2;
	while (div > 0)
	{
		count += value/div;
		value -= (value/div) * div;
		div /= 2;
	}
	if (sign > 0)
		return(count);
	return(8 * sizeof(int) - count);
}



