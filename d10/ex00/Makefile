CC=gcc
CFLAGS=-Wall -Wextra -I includes
NAME=libft.a
_SRC= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ= $(_SRC:.c=.o)
VPATH = srcs


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all