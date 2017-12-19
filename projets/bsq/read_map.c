#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "bsq.h"

/*
** is_windows = 1 => for files with newline = "\r\n"
*/
int get_line_length(int file_handle, int is_windows)
{
	int length;
	int file_not_finished;
	char buffer[1];

	length = 0;
	do
	{
		file_not_finished = read(file_handle, buffer, 1);
		length++;
	} while (buffer[0] != '\n' && file_not_finished != 0);
	length--;
	if (buffer[0] == '\n' && is_windows)
		length--;
	return(length);
}

/*
** is_windows = 1 => for files with newline = "\r\n"
*/
int get_file_parameters(char* filename, int size[2], char char_type[3], int is_windows)
{
	char buffer[1];
	char first_line[30];
	int file;
	int i;

	file = open(filename, O_RDONLY, S_IREAD);
	i = 0;
	do
	{
		read(file, buffer, 1);
		first_line[i++] = *buffer;
	} while (*buffer != '\n');
	first_line[i-1] = '\0';
	size[0] = ft_atoi(first_line);
	size[1] = get_line_length(file, is_windows);
	close(file);
	i = 0;
	while (first_line[i] >= '0' && first_line[i] <= '9')
		i++;
	char_type[0] = first_line[i];
	char_type[1] = first_line[i + 1];
	char_type[2] = first_line[i + 2];
	return(0);
}

/*
** Check file correctness. 0 if inccorrect, 1 if correct
** is_windows = 1 => for files with newline = "\r\n"
*/
int is_map_correct(char *filename, int size[2], char char_type[3], int is_windows)
{
	int file;
	int row;
	int i;
	char buffer[1];

	file = open(filename, O_RDONLY, S_IREAD);
	get_line_length(file, is_windows);
	row = 0;
	while (row < size[0])
	{
		if (get_line_length(file, is_windows) != size[1])
			return(0);
		row++;
	}
	close(file);
	file = open(filename, O_RDONLY, S_IREAD);
	get_line_length(file, is_windows);

	i = 0;
	while (i < (size[0] + 1 + is_windows) * size[1])
	{
		read(file, buffer, 1);
		if (buffer[0] != char_type[0] && buffer[0] != char_type[1] &&
			buffer[0] != '\n' && buffer[0] != '\r')
			return(0);
		i++;
	}
	return(1);
}


/*
** is_windows = 1 => for files with newline = "\r\n"
*/
int create_grid(char *filename, int size[2], char char_type[3], int **tab, int is_windows)
{
	int file;
	int row;
	int col;
	char *line;

	line = (char*)malloc(size[1] + 1);
	file = open(filename, O_RDONLY, S_IREAD);
	if (file == -1)
		return(-1);

	get_line_length(file, is_windows);
	row = 0;
	while (row < size[0])
	{
		read(file, line, size[1] + 1 + is_windows);
		tab[row] = (int*)malloc(size[1] * sizeof(int));
		col = 0;
		while (col < size[1])
		{
			tab[row][col] = (line[col] == char_type[1]);
			col++;
		}
		row++;
	}
	return(0);
}

void throw_map_error()
{
	write(2, "map error\n", 11);
}

