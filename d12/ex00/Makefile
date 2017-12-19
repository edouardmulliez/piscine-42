all: ft_display_file

ft_display_file: main.o
	gcc -o ft_display_file main.o

main.o: main.c 
	gcc -o main.o -c main.c -W -Wall -Werror -Wextra 

clean:
	rm -rf *.o

fclean: clean
	rm -rf ft_display_file