
#include <stdio.h>


int ft_strlen(char* str);
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_swap(int *a, int *b);
int ft_strcmp(char *s1, char *s2);

int main(void)
{
	char *s1 = "Hello";
	char *s2 = "Hello World";
	
	
	ft_putstr(s1);
	
	printf("\nLongueur de %s: %d", s1, ft_strlen(s1));
	printf("%s est plus grand que %s? %d", s1, s2, ft_strcmp(s1, s2));

	return(0);
}