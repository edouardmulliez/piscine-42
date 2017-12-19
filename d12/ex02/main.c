#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include "ft_tail.h"

int count_line(char *filename)
{	
	int fd;
	char buffer[1];
	int count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{		
		ft_puterror("Error code: ");
		ft_putnbr_error(errno);
		return(-1);
	}
	count = 1;
	while(read(fd, buffer, 1) != 0)
	{
		if (buffer[0] == '\n')
			count++;
	}
	return(count);
}


void pass_line(int fd)
{
	char buffer[1];
	buffer[0] = '0';
	while (buffer[0] != '\n')
	{
		read(fd, buffer, 1);
	}
}

void read_write_from(char *filename, int line_start)
{
	int fd;
	char buffer[1];
	int count;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{		
		ft_puterror("Error code: ");
		ft_putnbr_error(errno);
		return;
	}
	count = 0;
	while (count < line_start)
	{
		pass_line(fd);
		count++;
	}
	while(read(fd, buffer, 1) != 0)
		write(1, buffer, 1);
}

void read_write_last_10(char *filename)
{
	int line_count;

	line_count = count_line(filename);
	line_count -= 10;
	if (line_count < 0)
		line_count = 0;
	read_write_from(filename, line_count);
	ft_putchar('\n');
}

void read_write_from_stdin()
{
	int fd;
	int eof_check;
	char buffer[1];
	char first_line[60];
	int i;
	i = 0;
	fd = open("ft_tail_stdin", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	while (read(0, buffer, 1))
		write(fd, buffer, 1);
	close(fd);
}


int main(int argc, char* argv[])
{
	int i;
	if (argc == 1)
	{
		read_from_stdin();
		read_write_last_10("ft_tail_stdin");
	}
	i = 1;
	while (i < argc)
	{
		if (argc > 2)
			ft_put_header(argv[i]);
		read_write_last_10(argv[i]);
		i++;
	}
	return(0);
}


