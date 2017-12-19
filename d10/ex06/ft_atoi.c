
int ft_atoi(char *str)
{
    int str_len;
    int result;
    int mul;
    result = 0;
    mul = 1;
    str_len = 0;
    if (str[0] == '+' || str[0] == '-')
    	str_len++;
    while (str[str_len] - '0' >= 0 && str[str_len] - '9' <= 0)
    	str_len++;
    while (str_len > 0)
    {
        if (str[str_len-1] == '-')
            return(-result);
        if (str[str_len-1] == '+')
            return(result);
        result += (str[str_len - 1] - '0') * mul;
        mul *= 10;
        str_len--;
    }
    return(result);
}