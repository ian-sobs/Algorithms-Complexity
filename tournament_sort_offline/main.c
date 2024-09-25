#include<stdio.h>
#include "def.h"

int main(){
    int count = 5;
    int arr[5] = {1, 8, -5, 1, 0};
    int x;
    for(x = 0; x < count; ++x){
        printf("%d ", arr[x]);
    }

    printf("\n\n");

    tournament_sort(arr, count);

    for(x = 0; x < count; ++x){
        printf("%d ", arr[x]);
    }


    return 0;
}