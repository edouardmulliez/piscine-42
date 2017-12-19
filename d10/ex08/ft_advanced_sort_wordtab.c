

int ft_strcmp(char* s1, char* s2){
    int i = 0;
    int diff;
    while (s1[i] != '\0' && s1[i] != '\0'){
        diff = s1[i]-s2[i];
        if (diff > 0){
            return 1;
        }
        if (diff < 0){
            return -1;
        }
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
** Find index of the min element of tab[i:end]
*/
int find_min_index(char **tab, int i, int(*cmp)(char *, char *))
{
	int min_index;
	min_index = i;
	while(tab[i] != 0)
	{
		if (cmp(tab[min_index], tab[i]) > 0)
			min_index = i;
		i++;
	}
	return(min_index);
}

/*
** Exchange two pointers to strings
*/
void swap(char **i, char **d)
{
    char *t = *d;
    *d = *i;
    *i = t;
}

void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *))
{
	int i;
	int j;
	while (tab[i] != 0)
	{
		j = find_min_index(tab, i, cmp);
		swap(tab+i, tab+j);
		i++;
	}
}


