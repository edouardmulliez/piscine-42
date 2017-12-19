

#include <unistd.h>
#include <fcntl.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_puterror(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		write(2, &(str[i]), 1);
		i++;
	}
}

void read_write(char *filename)
{
	int fd;
	char buffer[1];
	fd = open(filename, O_RDONLY);

	while(read(fd, buffer, 1) != 0)
		write(1, buffer, 1);
}

int main(int argc, char* argv[])
{
	if (argc == 1)
		ft_puterror("File name missing.");
	if (argc > 2)
		ft_puterror("Too many arguments.");

	if (argc == 2)
		read_write(argv[1]);

	return(0);
}