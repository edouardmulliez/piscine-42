#include <stdlib.h>
#include "ft_perso.h"


int get_perso_nb(char *str)
{
	int i;
	int nb;
	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '|')
			nb++;
		i++;
	}
	return(nb);
}

/*
** str length with special separators (; | \0)
*/
int get_length(char *str)
{
	int i;
	i = 0;
	while ((str[i] != '\0') && (str[i] != '|') && (str[i] != ';'))
	{
		i++;
	}
	return(i);
}

int ft_atoi_base10(char *str)
{
    int str_len;
    int result;
    int j;
    int mul;
    str_len = get_length(str);
    result = 0;
    mul = 1;
    while (str_len > 0)
    {
        j = 0;
        while (j < 10)
        {
            if (str[str_len-1] == ('0'+j))
                result += j * mul;
            j++;
        }
        mul *= 10;
        str_len--;
    }
    return(result);
}

/*
** Read the age in str, starting from str[i[0]]. Put i[0] to the next position.
*/
int get_age(char *str, int *i)
{
	int age;
	age = ft_atoi_base10(str);
	*i = *i + get_length(str) + 1;
	return(age);
}

t_perso **ft_decrypt(char *str)
{
	t_perso **tab;
	int perso_nb;
	int i;
	int perso_i;
	int j;
	tab = (t_perso**)malloc(sizeof(t_perso*));
	perso_nb = get_perso_nb(str);
	tab[0] = (t_perso*)malloc(sizeof(t_perso) * perso_nb);
	i = 0;
	perso_i = 0;
	while (perso_i < perso_nb)
	{
		tab[0][perso_i].age = get_age(str+i, &i);
		tab[0][perso_i].name = (char*)malloc(sizeof(char) * get_length(str+i));
		j = 0;
		while ((str[i+j] != '\0') && (str[i+j] != ';'))
		{
			tab[0][perso_i].name[j] = str[i+j];
			j++;
		}
		tab[0][perso_i].name[j] = '\0';
		i += j + 1;
		perso_i++;
	}
	tab[0][perso_i].name = 0;
	return(tab);
}

