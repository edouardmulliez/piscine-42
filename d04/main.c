#include <stdio.h>
#include <stdlib.h>



int eight_queen_puzzle2(int* tab, int tab_len, int with_display){
    // Functions that return the number of possibilities to have 8 queens, knowing the emplacement of the 1st queens (in tab)

    int N = 8; // puzzle size
    int solution_nb = 0;
    int i;

    if (tab_len == N){
        if (with_display){
            display_tab(tab, tab_len);
        }
        return 1;
    }
    for (i=1; i <=N; i++){
        if (is_compatible(tab, tab_len, i)){
            tab[tab_len] = i;
            solution_nb += eight_queen_puzzle2(tab, tab_len+1, with_display);
        }
    }
    return solution_nb;
}

int is_compatible(int* tab, int tab_len, int candidate){
    // check if i can be a correct position in the puzzle
    int i, diff;

    if (tab_len == 0){
        return 1;
    }
    for (i = 0; i<tab_len; i++){
        diff = tab_len - i;
        if (tab[i] == candidate || tab[i]+diff == candidate || tab[i]-diff == candidate){
            return 0;
        }
    }
    return 1;
}

int eight_queen_puzzle(void){
    int tab[8];
    int tab_len = 0;

    return eight_queen_puzzle2(tab, tab_len, 0);
}

void eight_queen_puzzle_2(void){
    int tab[8];
    int tab_len = 0;
    eight_queen_puzzle2(tab, tab_len, 1);
}

void display_tab(int* tab, int tab_len){
    int i;
    for (i=0; i<tab_len; i++){
        printf("%d", tab[i]);
    }
    printf("\n");
}


//int main()
//{
//    printf("%d", eight_queen_puzzle());
////    eight_queen_puzzle_2();
//    return 0;
//}
