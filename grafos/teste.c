#include <stdio.h>

int teste(int a) {
    if(a == 0) return 0;
    else{ 
        int b = (a + teste (a-1));
        return b;
    }
}


int main(){

    int abc = teste(7);

    printf("%d\n", abc);
    return 0;
}