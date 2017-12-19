
char *ft_strstr(char *str, char *to_find);
int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strupcase(char *str);
char *ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, int nb);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putnbr_base(int nbr, char *base); 
int ft_atoi_base(char *str, char *base);
void ft_putstr_non_printable(char *str); 
void *ft_print_memory(void *addr, unsigned int size);


/*
** d06  : create a library and use program parameters
*/

libft.a
ft_print_program_name.c
ft_print_params.c
ft_rev_params.c
ft_sort_params.c

/*
** d07 : use of malloc
*/

char *ft_strdup(char *src);
int *ft_range( int min, int max);
int ft_ultimate_range( int **range, int min, int max);
char *ft_concat_params( int argc, char **argv);
char **ft_split_whitespaces(char *str);
void ft_print_words_tables(char **tab);
char *ft_convert_base(char *nbr, char *base_from, char *base_t);
char **ft_split(char *str, char *charset);

/*
** d08 : day with the header files
*/

struct s_stock_par *ft_param_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_par *par);

