
#include "eval_expr.h"

/*
** Find max index i such that
** 	start <= i <= end
** 	str[i] in sep
**  str[i] is not between parentheses '(....)'
*/
int find_sep_index(char *str, char *sep, int start, int end)
{
	int i;
	int max_index;
	int par_count;

	max_index = -1;
	i = start;
	par_count = 0;
	while (i  <= end)
	{
		if (str[i] == '(')
			par_count++;
		if (str[i] == ')')
			par_count--;
		if (char_in_str(sep, str[i]) && (par_count == 0))
			max_index = i;
		i++;
	}
	return(max_index);
}

/*
** Find indices of 1st and last parentheses between start and end in str.
*/
void find_par_index(char *str, int pos[2], int start, int end)
{
	int i;
	int is_first;

	pos[0] = -1;
	is_first = 1;
	i = start;
	while (i <= end)
	{
		if ((str[i] == '(') && is_first)
		{
			pos[0] = i;
			is_first = 0;
		}
		if (str[i] == ')')
			pos[1] = i;
		i++;
	}
}

void find_nb_index(char *str, int pos[2], int start, int end)
{
	int i;
	int is_first;

	pos[0] = -1;
	is_first = 1;
	i = start;
	while (i <= end)
	{
		if ((str[i] >= '0') && (str[i] <= '9') && is_first)
		{
			pos[0] = i;
			is_first = 0;
		}
		if ((str[i] >= '0') && (str[i] <= '9'))
			pos[1] = i;
		i++;
	}
}
