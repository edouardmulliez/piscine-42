

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