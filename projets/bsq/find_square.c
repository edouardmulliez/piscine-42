#include <stdlib.h>

/*
** For each cell, gives how much "width" to the right before obstacle
*/
void create_width_tab(int **grid, int **width_tab, int size[2])
{
	int row;
	int col;
	row = 0;
	while (row < size[0])
	{
		width_tab[row] = (int*)malloc(size[1] *sizeof(int));
		width_tab[row][size[1] - 1] = (grid[row][size[1] - 1] == 0);
		col = size[1] - 2;
		while (col >= 0)
		{
			width_tab[row][col] = width_tab[row][col + 1] + 1;
			if (grid[row][col] == 1)
				width_tab[row][col] = 0;
			col--;
		}
		row++;
	}
}

/*
** For each cell, give the max size of a square whose up-left corner is in the cell.
*/
void get_max_size_tab(int **width_tab, int **size_tab, int size[2])
{
	int row;
	int col;
	int min_width;
	int i;
	row = 0;
	while (row < size[0])
	{
		size_tab[row] = (int*)malloc(size[1] * sizeof(int));
		col = 0;
		while(col < size[1])
		{
			size_tab[row][col] = 0;
			min_width = width_tab[row][col];
			i = 0;
			while ((row + i < size[0]) && (i < min_width))
			{
				if (width_tab[row + i][col] < min_width)
					min_width = width_tab[row + i][col];
				if (i < min_width)
					size_tab[row][col] = i + 1;
				i++;
			}
			col++;
		}
		row++;
	}
}

void get_max_sq_position(int **max_size_tab, int position[2], int max_size[1], int size[2])
{
	int row;
	int col;
	max_size[0] = 0;
	row = 0;
	col = 0;
	while (row < size[0])
	{
		while (col < size[1])
		{
			if (max_size_tab[row][col] > max_size[0])
			{
				max_size[0] = max_size_tab[row][col];
				position[0] = row;
				position[1] = col;
			}
			col++;
		}
		row++;
	}
}
