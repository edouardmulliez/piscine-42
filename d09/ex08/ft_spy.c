#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}
char* ft_strlowcase(char* str){
    int i = 0;

    while (str[i] != '\0'){
        // test if uppercase character
        if (str[i]-'A'>=0 && str[i]-'Z'<=0){
            str[i] += 'a'-'A';
        }
        i++;
    }
    return str;
}

/*
** Is needle in str?
*/
int ft_match(char *str, char *needle, int started)
{
	if (needle[0] == '\0')
		return(1);
	if (str[0] == ' ' && !started)
		return(ft_match(str+1, needle, 0));
	if (str[0] != needle[0])
		return(0);
	return(ft_match(str+1, needle+1, 1));
}

void ft_spy(int ac, char **av)
{
	int i;
	int alert;
	i = 1;
	alert = 0;
	while (i < ac)
	{
		av[i] = ft_strlowcase(av[i]);
		if (ft_match(av[i], "powers", 0) ||
			ft_match(av[i], "president", 0) ||
			ft_match(av[i], "attack", 0))
			alert = 1;
		i++;
	}
	if (alert)
		ft_putstr("Alert!!!\n");
}


int main(int argc, char *argv[])
{
	ft_spy(argc, argv);
}