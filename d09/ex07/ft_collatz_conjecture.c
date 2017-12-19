
unsigned int ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return(0);
	if (base % 2 == 0)
		return(1 + ft_collatz_conjecture(base/2));
	return(1 + ft_collatz_conjecture(3 * base + 1));
}