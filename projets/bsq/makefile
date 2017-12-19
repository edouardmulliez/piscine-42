CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=
EXEC=bsq
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)
bsq: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
main.o: bsq.h
read_map.o: bsq.h
read_stdin.o: bsq.h
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -f *.o core
mrproper: clean
	rm -f $(EXEC)