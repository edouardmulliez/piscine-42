#include <stdio.h>
#include <stdlib.h>

char* ft_strcpy(char* dest, char* src){
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

/*
** Append src to dest
*/
void ft_concat(char *dest, const char *src)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	dest[i] = '\n';
	while (src[j] != '\0')
	{
		dest[i+1+j] = src[j];
		j++;
	}
	dest[i+1+j] = '\0';
}

char *ft_concat_params(int argc, char **argv)
{
	int i;
	int j;
	int count;
	char *result;
	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
			count++;
		}	
		i++;
	}
	result = malloc(sizeof(char) * (count + argc - 1));
	if (result == NULL)
		return(NULL);
	i = 2;
	if (argc > 1)
		ft_strcpy(result, argv[1]);
	while (i < argc)
		ft_concat(result, argv[i++]);
	return(result);
}


int main(int argc, char *argv[])
{	
	printf("Concatenated parameters: %s ", ft_concat_params(argc, argv));
	return(0);
}


