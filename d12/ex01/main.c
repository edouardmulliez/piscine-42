#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putchar_error(char c)
{
	write(2, &c, 1);
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

void ft_putnbr_error(int nb)
{
	if (nb < 0)
	{
		ft_putchar_error('-');
		nb = -nb;
	}

	if (nb > 9)
	{
		ft_putnbr_error(nb/10);
		ft_putnbr_error(nb - (nb/10) * 10);
	}
	else
	{
		ft_putchar_error('0' + nb);
	}
}

void read_write(char *filename)
{
	int fd;
	char buffer[1];
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{		
		ft_puterror("Error code: ");
		ft_putnbr_error(errno);
		return;
	}
	while(read(fd, buffer, 1) != 0)
		write(1, buffer, 1);
}

int main(int argc, char* argv[])
{
	int i;
	if (argc == 1)
		ft_puterror("File name missing.");

	i = 1;
	while (i < argc)
	{
		read_write(argv[i]);
		i++;
	}

	return(0);
}


