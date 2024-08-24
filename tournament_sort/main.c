#include "def.h"

int main(){
    int count = 10;
    int a[SIZE] = {-1, -2, 3, 2, 2, 9, 7, 7, 5, 4};
    int temp[MAX_SIZE] = {0};

    printf("Before tournament:\n");
    display(a, count);

    tournament_sort(a, temp, count);

    printf("After tournament:\n");
    display(a, count);
    
    return 0;
}