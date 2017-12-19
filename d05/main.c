#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isprint
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char* ft_strcpy(char* dest, char* src){
    int i =0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

char* ft_strncpy(char* dest, char* src, unsigned int n){
    int i = 0, end = 0;

    while (i < n){
        if (src[i] == '\0'){
            end = 1;
        }
        if (end){
            dest[i] = '\0';
        }else{
            dest[i] = src[i];
        }
        i++;
    }
    return dest;
}

char* ft_strstr(char* str, char* to_find){
    int i = 0;
    int j;
    while (str[i] != '\0'){
        j=0;
        while (str[i+j] == to_find[j] && str[i+j]!='\0' && to_find[j]!='\0'){
            j++;
        }
        if (to_find[j] == '\0'){
            return str+i;
        }
        i++;
    }
    return NULL;
}

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
    if (s1[i] == '\0' && s2[i] == '\0'){
        return 0;
    }
    if (s1[i] == '\0'){
        return -1;
    }
    if (s2[i] == '\0'){
        return 1;
    }
}

int ft_strncmp(char* s1, char* s2, unsigned int n){
    int i = 0;
    int diff;

    while (s1[i] != '\0' && s1[i] != '\0' && i < n){
        diff = s1[i]-s2[i];
        if (diff != 0){
            return diff;
        }
        i++;
    }
    if (i == n){
        return 0;
    }
    diff = s1[i]-s2[i];
    return diff;
}

char* ft_strupcase(char* str){
    int i = 0;

    while (str[i] != '\0'){
        // test if lowercase character
        if (str[i]-'a'>=0 && str[i]-'z'<=0){
            str[i] += 'A'-'a';
        }
        i++;
    }
    return str;
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

int is_alpha_char(char c){
    // check if c is an alphanumeric character
    if ((c-'a'>=0 && c-'z'<=0) ||
        (c-'A'>=0 && c-'Z'<=0) ||
        (c-'0'>=0 && c-'9'<=0)){
            return 1;
        }else{
            return 0;
        }
}

char* ft_strcapitalize(char* str){
    int i = 0;
    int is_first = 1; // test if character is 1st character of word
    while (str[i]!='\0'){
        if (is_alpha_char(str[i])){
            if (is_first){
                // put char to upper
                if (str[i]-'a'>=0 && str[i]-'z'<=0){
                    str[i] += 'A'-'a';
                }
            }else{
                //put char to lower
                if (str[i]-'A'>=0 && str[i]-'Z'<=0){
                    str[i] += 'a'-'A';
                }
            }
            is_first = 0;
        }else{
            is_first = 1;
        }
        i++;
    }
    return str;
}

int ft_str_is_alpha(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (!((str[i]-'a'>=0 && str[i]-'z'<=0) || (str[i]-'A'>=0 && str[i]-'Z'<=0))){
            return 0;
        }

        i++;
    }
    return 1;
}

int ft_isprint(char c){
    // test if char c is printable (same as isprint function)
    if ( c >= 0x20 && c <= 0x7e )
        return 1;
    return 0;
//    if (c-'A' >= -33){
//        return 1;
//    }else{
//        return 0;
//    }
}

int ft_str_is_printable(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (!ft_isprint(str[i])){
            return 0;
        }
        i++;
    }
    return 1;
}

char* ft_strcat(char* dest, char* src){
    int i=0, j=0;
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

char *ft_strncat(char* dest, char* src, int nb)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < nb)
    {
        dest[i+j] = src[j];
        j++;
    }
    dest[i+j] = '\0';
    return dest;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int len;
    int i;
    int j;
    i = 0;
    j = 0;
    while (dest[i]!='\0' && i < size)
        i++;
    while (i+j<size && src[j] != '\0')
    {
        dest[i+j] = src[j];
        j++;
    }
    dest[i+j] = '\0';
    return(i+j);
}

unsigned int strlcpy(char *dest, const char *src, unsigned int size)
{
    int i;
    i = 0;
    while (src[i] != '\0' && i < size)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(i);
}

void ft_putnbr_base(int nbr, char *base)
{
    int div;
    int base_len;
    base_len = ft_check_base(base);
    if (base_len < 2)
        return;
    if (nbr<0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    div = find_biggest_divider(nbr, base_len);
    while (div > 0)
    {
        ft_putchar(base[nbr/div]);
        nbr -= (nbr/div) * div;
        div /= base_len;
    }
}

/*
** check_base function (return base length if base is correct else 0)
*/
int ft_check_base(char *base)
{
    int i;
    int j;
    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == '+' || base[i] == '+')
            return(0);
        j = i+1;
        while (base[j] != '\0')
        {
            if (base[i] == base[j])
                return(0);
            j++;
        }
        i++;
    }
    return(i);
}

/*
** find biggest base^p divider for n. If base_len=10, and n=2347, then biggest_divider = 1000
*/
int find_biggest_divider(int n, int base_len)
{
    int divider;
    divider = 1;
    while (divider*base_len < n)
        divider *= base_len;
    return(divider);
}

/*
** check_str_base: check if str can be valid for base (if not, return 0).
** If valid, return str length
*/
int check_str_base(char *str, char *base)
{
    int i;
    int j;
    int is_in_base;
    i = 0;
    while (str[i] != '\0')
    {
        if (!(i == 0 && (str[i]=='+' || str[i]=='-')))
        {
            is_in_base = 0;
            j = 0;
            while (base[j] != '\0')
            {
                is_in_base += (str[i] == base[j]);
                j++;
            }
            if (!is_in_base)
                return(0);
        }
        i++;
    }
    return(i);
}

int ft_atoi_base(char *str, char *base)
{
    int base_len;
    int str_len;
    int result;
    int j;
    int mul;
    base_len = ft_check_base(base);
    str_len = check_str_base(str, base);
    result = 0;
    mul = 1;
    while (str_len > 0 && base_len > 1)
    {
        if (str[str_len-1] == '-')
            return(-result);
        if (str[str_len-1] == '+')
            return(result);
        j = 0;
        while (base[j] != '\0')
        {
            if (str[str_len-1] == base[j])
                result += j * mul;
            j++;
        }
        mul *= base_len;
        str_len--;
    }
    return(result);
}

// convert a char to hexa format (2 digits)
void ft_putchar_hexa(char c)
{
    int a;
    int div;
    int base_len;
    char *base;
    base_len = 16;
    div = 16;
    base = "0123456789abcdef";
    a = (unsigned int) c;

    printf("%d \n", a);

    ft_putchar('\\');
    while (div > 0)
    {
        ft_putchar(base[a/div]);
        a -= (a/div) * div;
        div /= base_len;
    }
}

ft_putstr_non_printable(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isprint(str[i]))
        {
            ft_putchar(str[i]);
        }
        else
        {
            ft_putchar_hexa(str[i]);
        }
        i++;
    }
}

int main()
{

//    char src[40];
//    char dest[100];
//    char* needle;
//    memset(dest, '\0', sizeof(dest));
//    ft_strcpy(src, "This is tutorialspoint.com");
//    ft_strcpy(dest, src);
//    printf("Final copied string : %s\n", dest);

//    ft_strcpy(src, "This is tutorialspoint.com");
//    ft_strncpy(dest, src, 5);
//    printf("Final copied string : %s\n", dest);

//    needle = ft_strstr("un beau mot doux", "mot");
//    printf("Final copied string : %s\n", needle);


//    // Some test on characters
//    char a = 'A';
//    int i;
//    for (i=0; i<= 257; i++){
//        char test = a+i;
//        printf("Le charactere numero %d (%c) est affichable: %d. Sa difference avec %c est %d \n", i, test, isprint(test), a, test-a);
//    }
//    int nb;
//    char c1=' ';
//    char c2='A';
//    printf("La difference entre %c et %c est : %d", c1, c2, c1-c2);

//    char* s1 = "defezd";
//    char* s2 = "asad";
//    printf("%d \n", strcmp(s1, s2));
//    printf("%d \n", ft_strcmp(s1, s2));

//    char* s1 = "absadea";
//    char* s2 = "asade";
//    printf("%d \n", strncmp(s1, s2, 5));
//    printf("%d \n", ft_strncmp(s1, s2, 5));

//    char string1[] =  "hello, My name is WHAT, ùy !kd*%.;";
//    printf("%s \n", ft_strupcase(string1));
//    printf("%s \n", ft_strlowcase(string1));

//    char string1[] =  "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
//    printf("%s \n", ft_strcapitalize(string1));

//    char string1[] =  "salutAKBDun";
//    printf("%d \n", ft_str_is_alpha(string1));

//    printf("%d \n", ft_str_is_printable("adldlnd eknf \t"));

//    char string1[] =  "hello";
//    char string2[] =  "World";
//    printf("%s \n", ft_strcat(string1, string2));
//    printf("%s \n", ft_strncat(string1, string2, 3));

//    char string1[] =  "hello";
//    char string2[] =  "World";
//    printf("%d \n", ft_strlcat(string1, string2, 7));
//    printf("%s \n", string1);

//    ft_putnbr_base(2344, "01");

//    printf("%d \n", ft_atoi_base("-343", "0123456789"));
//    printf("%d \n", ft_atoi_base("34AB", "0123456789ABCEDF"));

//    ft_putstr_non_printable("Salut \n Comment vas-tu? $*µ%ù");

    ft_putchar_hexa('ù');

    return(0);
}
