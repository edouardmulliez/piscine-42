#include <stdio.h>

int ft_compact(char **tab, int length);

int main()
{
	int length;
	char * array[] = {
	    "First entry",
	    "Second entry",
	    0,
	    "Third entry"
	};
	length = ft_compact(array, 4);
	printf("array[2]: %s\n", array[2]);
	printf("New length: %d\n", length);
	return(0);
}