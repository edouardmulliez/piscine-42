#include <stdlib.h>
#include <stdio.h>

int ft_strlen(const char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

char* ft_strcpy(char* dest, const char* src){
    int i =0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

char *ft_strdup (const char *s) {
    char *d;
	d = malloc(ft_strlen(s) + 1);
    if (d == NULL)
		return NULL;
    ft_strcpy(d,s);
    return d;
}


int main()
{
	char *s1 = "Hello";
	char *s2;
	s2 = ft_strdup(s1);
	printf("s2: %s \n", s2);
	return(0);
}