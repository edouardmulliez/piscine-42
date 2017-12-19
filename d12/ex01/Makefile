CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=
EXEC=ft_cat
SRC= main.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(EXEC)
			