C=gcc
CFLAGS=-Wall -Wextra 
EXEC=do-op
SRC= main.c error.c ft_atoi.c operation.c print.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) -o $@ $^ 

main.o: header.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


