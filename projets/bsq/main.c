#include <stdlib.h>
#include "bsq.h"

#include <fcntl.h>
#include <unistd.h>

void free_tab(int **tab, int nrow)
{
	int i;
	i = 0;
	while (i < nrow)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void find_and_print_square(char *filename, int is_windows)
{
	int  size[2];
	char char_type[3];
	int  **grid;
	int  **width_tab;
	int  **size_tab;
	int  position[2];
	int  max_size;

	get_file_parameters(filename, size, char_type, is_windows);
	if (!is_map_correct(filename, size, char_type, is_windows))
		return(throw_map_error());

	grid = (int**)malloc(size[0] * sizeof(int*));
	width_tab = (int**)malloc(size[0] * sizeof(int*));
	size_tab = (int**)malloc(size[0] * sizeof(int*));

	create_grid(filename, size, char_type, grid, is_windows);
	create_width_tab(grid, width_tab, size);	
	get_max_size_tab(width_tab, size_tab, size);	
	get_max_sq_position(size_tab, position, &max_size, size);
	print_result_board(grid, position, max_size, size, char_type);

	free_tab(grid, size[0]);
	free_tab(width_tab, size[0]);
	free_tab(size_tab, size[0]);
}





// still to do: free memory...

int main(int argc, char *argv[])
{
	int i;
	
	if (argc == 1)
	{
		read_write_stdin();
		find_and_print_square("stdin_map", 0);
	}

	i = 1;
	while (i < argc)
	{
		find_and_print_square(argv[i], 1);
		i++;
	}
	return(0);
}