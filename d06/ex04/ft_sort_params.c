#include <stdio.h>

void ft_putchar(char c);
void ft_putstr(char *str);


/*
** Insert a string element in a string array of lenght len, at position position.
*/
void ft_insert(char **tab, char* element, int position, int len)
{
	int i;
	i = len - 1;
	while (i >= position)
	{
		tab[i+1] = tab[i];
		i--;
	}		
	if (len == 0)
		i = 0;
	tab[position] = element;
}

int ft_strcmp(char* s1, char* s2){
    int i = 0;
    int diff;
    while (s1[i] != '\0' && s1[i] != '\0'){
        diff = s1[i]-s2[i];
        if (diff > 0)
			return 1;
        if (diff < 0)
			return -1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
		return 0;
    if (s1[i] == '\0')
		return -1;
    if (s2[i] == '\0')
		return 1;
	return(0);
}

/*
** Insert a string element in a sorted string array of lenght len, at right position.
*/
void ft_insert_sorted(char **tab, char* element, int len)
{
	int i;
	i = 0;
	while (i < len && ft_strcmp(element, tab[i]) > 0)
		i++;
	ft_insert(tab, element, i, len);
}



int main (int argc, char *argv[])
{
	int i;
	int j;
	char *parameter;
	char *tab[argc-1];
	i = 1;
	while (i < argc)
	{
		ft_insert_sorted(tab, argv[i], i-1);
		i++;
	}
	i = 0;
	while (i < argc-1)
	{
		ft_putstr(tab[i]);
		i++;
		if (i<argc-1)
			ft_putchar('\n');
	}
	return(0);
}
