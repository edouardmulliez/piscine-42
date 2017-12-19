#include <unistd.h>
#include <stdio.h>


int get_number(int hour)
{
	int nb;
	nb = hour % 12;
	if (nb == 0)
		nb = 12;
	return(nb);
}

char get_letter(int hour)
{
	if (hour >= 12)
		return('P');
	return('A');
}

void ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %c.M. ", get_number(hour), get_letter(hour));
	hour = (hour + 1) % 24; 
	printf("AND %d.00 %c.M", get_number(hour), get_letter(hour));
}

int main()
{
	ft_takes_place(11);
}