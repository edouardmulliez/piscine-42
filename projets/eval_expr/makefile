CC=gcc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=
EXEC=eval_expr
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
eval_expr.o: eval_expr.h
eval.o: eval_expr.h
find.o: eval_expr.h
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -f *.o core
fclean: clean
	rm -f $(EXEC)