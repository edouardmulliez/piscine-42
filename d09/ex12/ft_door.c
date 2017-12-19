#include <unistd.h>
#include "ft_door.h"
void ft_putstr(char *str)
{
	while (str[0] != '\0')
		write(1, str++, 1);
}
void close_door(t_door *door)
{
	ft_putstr("Door closing...\n");
	door->state = CLOSE;
}
void open_door(t_door *door)
{
	ft_putstr("Door opening...\n");
	door->state = OPEN;
}
ft_bool is_door_open(t_door *door)
{
	ft_putstr("Door is open ?\n");
	return (door->state == OPEN);
}
ft_bool is_door_close(t_door* door)
{
	ft_putstr("Door is close ?\n") ;
	return (door->state == CLOSE);
}