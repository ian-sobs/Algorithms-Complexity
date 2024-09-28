//Reference code: https://en.oi-wiki.org/basic/tournament-sort/

#include "def.h"

int main(){
    int count = 6;
    int a[SIZE] = {3, -2, -3, -2, 10, 9};
    int temp[MAX_SIZE] = {0};

    printf("Before tournament:\n");
    display(a, count);

    tournament_sort(a, temp, count);

    printf("After tournament:\n");
    display(a, count);
    
    return 0;
}