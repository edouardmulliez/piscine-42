#include <stdlib.h>


char* ft_strcpy(char* dest, char* src){
    int i =0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

/*
** Returns 1 if char c is in str
*/
int ft_char_in_str(char c, char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return(1);
		i++;
	}
	return(0);
}


/*
** Function to count words in str (words are separated by any char in sep)
*/
int ft_count_words(char *str, char* sep)
{
	int i;
	int word_count;
	int sep_before;
	i = 0;
	sep_before = 1;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_in_str(str[i], sep))
		{
			if (sep_before)
				word_count++;
			sep_before = 0;
		}
		else
		{
			sep_before = 1;
		}
		i++;
	}
	return(word_count);
}


/*
** Get location of first char of next word and put next word length in length
*/
int ft_get_location(int i, int len[], char *str, char *sep)
{
	int j;
	j = 0;
	while (ft_char_in_str(str[i], sep))
		i++;
	while (!ft_char_in_str(str[i+j], sep) && str[i+j] != '\0')
		j++;
	len[0] = j;	
	return(i);
}


char **ft_split(char* str, char *charset)
{
	int i;
	int word_i;
	int char_i;
	int word_nb;
	int len[1];
	char **word_tab;
	i = 0;
	word_i = 0;
	word_nb = ft_count_words(str, charset);
	word_tab = (char**)malloc(sizeof(char*) * (word_nb + 1));
			
	while (str[i] != '\0')
	{
		i = ft_get_location(i, len, str, charset);
		if (len[0] == 0)
			break;
		word_tab[word_i] = (char*)malloc(sizeof(char) * (len[0] + 1));
		char_i = 0;
		while (char_i < len[0])
		{
			word_tab[word_i][char_i] = str[i + char_i];
			char_i++;
		}
		word_tab[word_i][char_i] = '\0';
		word_i++;
		i = i + len[0];	
	}
	word_tab[word_i] = 0;
	return(word_tab);
}
