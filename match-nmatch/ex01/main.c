#include <stdio.h>

int nmatch(char *s1, char *s2);

int main(int argc, char* argv[])
{
	if (argc == 3)
		printf("nmatch(%s, %s)?  %d \n", argv[1], argv[2], nmatch(argv[1], argv[2]));

	return(0);
}
