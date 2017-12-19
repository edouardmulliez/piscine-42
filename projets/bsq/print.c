#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_result_board(int **grid, int position[2], int square_size, int size[2], char char_type[3])
{
	int row;
	int col;
	row = 0;
	while (row < size[0])
	{
		col = 0;
		while (col < size[1])
		{
			if (row >= position[0] && row < position[0] + square_size &&
				col >= position[1] && col < position[1] + square_size)
			{
				ft_putchar(char_type[2]);
			}
			else
			{
				ft_putchar(char_type[ grid[row][col] ]);
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
}
