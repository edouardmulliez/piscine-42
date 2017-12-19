#include <stdio.h>
#include <stdlib.h>




int ft_sqrt(int nb){
    int i = 0;

    while (i*i < nb){
        i++;
    }
    if (i*i == nb){
        return i;
    }else{
        return 0;
    }
}

int is_prime(int nb){
    int i = 2;
    if (nb == 0 || nb ==1){
        return 0;
    }
    while (i < nb){
        if (is_divided(nb, i)){
            return 0;
        }
        i++;
    }
    return 1;
}

int is_divided(int a, int b){
    // Is a divisible by b
    int i = 1;
    while (b*i < a){
        i++;
    }
    if (b*i == a){
        return 1;
    }else{
        return 0;
    }
}

int ft_find_next_prime(int nb){
    while (!is_prime(nb)){
        nb++;
    }
    return nb;
}

int main()
{
//    printf("%d", ft_sqrt(26));

//    printf("%d", is_prime(17));
    printf("%d", ft_find_next_prime(14));
    return 0;
}
