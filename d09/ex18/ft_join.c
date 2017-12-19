#include <stdlib.h>


char* ft_strcat(char* dest, char* src){
    int i;
    int j;
    i = 0;
    j = 0;
    while (dest[i] != '\0'){
        i++;
    }
    while (src[j] != '\0'){
        dest[i+j] = src[j];
        j++;
    }
    dest[i+j] = '\0';
    return dest;
}

int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}
int get_tab_length(char **tab, char *sep)
{
	int i;
	int count;
	i = 0;
	count = 0;
	while (tab[i] != 0)
		count += ft_strlen(tab[i++]);
	count += i * ft_strlen(sep);
	return(count);
}

char *ft_join(char **tab, char *sep)
{
	char *str;
	int i;
	str = (char*)malloc(sizeof(char) * get_tab_length(tab, sep));
	i = 1;
	str[0] = '\0';
	if (tab[0] != 0)
		ft_strcat(str, tab[0]);
	while (tab[i] != 0)
	{
		ft_strcat(str, sep);
		ft_strcat(str, tab[i]);
		i++;
	}
	return(str);
}

