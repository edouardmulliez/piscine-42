

int match(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return(1);
	if (s1[0] == '\0' && s2[0] == '*')
		return(match(s1, s2+1));
	if (s1[0] == '\0')
		return(0);
	if (s2[0] == '\0')
		return(0);
	if (s1[0] == s2[0])
		return(match(s1+1, s2+1));
	if (s2[0] == '*')
		return(match(s1+1, s2) || match(s1, s2+1));
	return(0);
}


