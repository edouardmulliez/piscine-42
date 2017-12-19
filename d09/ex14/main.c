#include <stdio.h>
#include "ft_perso.h"

t_perso **ft_decrypt(char *str);

int main()
{
	t_perso **tab;
	int i;
	tab = ft_decrypt("12|Lucie;23|Robert;54|Marco");
	i = 0;
	while (tab[0][i].name)
	{
		printf("Nom: %s \n", tab[0][i].name);
		printf("Age: %d \n", tab[0][i].age);
		i++;
	}
	return(0);

}