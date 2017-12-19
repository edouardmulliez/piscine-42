#include <stdio.h>

int match(char *s1, char *s2);

int main(int argc, char* argv[])
{
	if (argc == 3)
		printf("match(%s, %s)?  %d \n", argv[1], argv[2], match(argv[1], argv[2]));

	return(0);
}
