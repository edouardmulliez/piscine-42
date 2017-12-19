
void ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int b_0;
	b_0 = *b;
	*b = ****d;
	****d = *******c;
	*******c = ***a;
	***a = b_0;
}
