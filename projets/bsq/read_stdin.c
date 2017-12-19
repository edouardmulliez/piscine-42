#include <fcntl.h>
#include <unistd.h>

#include "bsq.h"

void read_write_line_from_stdin(int fd, int line_nb)
{
	int eof_check;
	int i;
	char buffer[1];
	i = 0;
	while (i < line_nb)
	{
		do
		{
			eof_check = read(0, buffer, 1);
			write(fd, buffer, 1);
		} while (eof_check != 0 && buffer[0] != '\n');
		i++;
	}
}

void read_write_stdin()
{
	int fd;
	int eof_check;
	char buffer[1];
	char first_line[60];
	int i;
	i = 0;
	fd = open("stdin_map", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	do
	{
		eof_check = read(0, buffer, 1);
		write(fd, buffer, 1);
		first_line[i] = buffer[0];
		i++;
	} while (eof_check != 0 && buffer[0] != '\n');
	first_line[i-1] = '\0';
	read_write_line_from_stdin(fd, ft_atoi(first_line));
	close(fd);
}