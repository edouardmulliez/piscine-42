
#include <stdio.h>


void ft_putchar(char c);

int lines_in_sastantua(int size)
{
	if (size == 1)
		return(3);
	return(lines_in_sastantua(size - 1) + size + 2);
}

int stars_in_line(int line)
{
	int jump;
	int i;

	if (line == 1)
		return(1);
	jump = 0;
	i = 1;
	while (lines_in_sastantua(i) <= (line - 1))
	{
		if ((line - 1) == lines_in_sastantua(i))
			jump = 1;
		i++;
	}
	if (jump)
		return(stars_in_line(line - 1) + 6);
	return(stars_in_line(line - 1 ) + 2);
}

int spaces_in_line(int line, int size)
{
	int jump;
	int i;

	if (line == lines_in_sastantua(size))
		return(0);
	jump = 0;
	i = 1;
	while (lines_in_sastantua(i) <= line)
	{
		if (line == lines_in_sastantua(i))
			jump = 1;
		i++;
	}
	if (jump)
		return(spaces_in_line(line + 1, size) + 3);
	return(spaces_in_line(line + 1, size) + 1);
}

void draw_line(int spaces, int stars, int doors, int knob)
{
	int i;

	i = 0;
	while (i < (spaces + stars + 2))
	{
		if (i < spaces)
			ft_putchar(' ');
		if (i == spaces)
			ft_putchar('/');
		if ( ((i > spaces) && (i <= spaces + (stars-doors)/2)) ||
		  ((i > spaces + (stars+doors)/2) && (i < (spaces + stars + 1))))
			ft_putchar('*');
		if (!knob && (i > spaces + (stars-doors)/2) && (i <= spaces + (stars+doors)/2))
			ft_putchar('|');
		if (knob && (i > spaces + (stars-doors)/2) && (i <= spaces + (stars+doors)/2) &&
			(i != spaces + (stars + 3)/2))
			ft_putchar('|');
		if (knob && (i == spaces + (stars + 3)/2))
			ft_putchar('$');
		if (i == (spaces + stars + 1))
			ft_putchar('\\');
		i++;
	}
	ft_putchar('\n');
}

void sastantua(int size)
{
	int lines;
	int line;
	int door_size;
	int doors;
	int knob;

	if (size < 1)
		return;

	door_size = size;
	if (size == (size/2)*2)
		door_size -=1;
	lines = lines_in_sastantua(size);
	line = 1;
	while (line <= lines)
	{
		doors = 0;
		knob = 0;
		if (lines - line < door_size)
			doors = door_size;
		if ((lines - line == (door_size-1)/2) && size >= 5)
			knob = 1;
		draw_line(spaces_in_line(line, size), stars_in_line(line), doors, knob);
		line++;
	}
}



int ft_atoi(char *str)
{
	int nb;
	nb = 0;
	while (str[0] != '\0' && str[0] >= '0' && str[0] <='9')
	{
		nb *= 10;
		nb += str[0] - '0';
		str++;
	}
	return(nb);
}

// int main(int argc, char *argv[])
// {
// 	if (argc > 1)
// 	{
// 		sastantua(ft_atoi(argv[1]));
// 	}

// 	return(0);
// }

int main()
{
	int i;
	i = 0;
	while (i < 7)
	{
		ft_putchar('0'+i);
		ft_putchar('\n');
		sastantua(i);
		i++;
	}
	return(0);
}


