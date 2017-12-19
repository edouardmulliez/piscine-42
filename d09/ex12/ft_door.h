#ifndef FT_DOOR_H
#define FT_DOOR_H

#define EXIT_SUCCESS 0
#define OPEN		 1
#define CLOSE		 0

typedef struct s_door
{
	int state;
} t_door;
typedef int ft_bool;

void ft_putstr(char *str);
void close_door(t_door *door);
void open_door(t_door *door);
ft_bool is_door_open(t_door *door);
ft_bool is_door_close(t_door* door);

#endif