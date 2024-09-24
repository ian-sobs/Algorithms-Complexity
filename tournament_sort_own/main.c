#include<stdio.h>
#include "def.h"

int main(){
    int count = 12;
    int arr[12] = {85, -62, 61, 90, -96, 1, 8, -5, 1, 0, -1, -2};
    int x;
    for(x = 0; x < 12; ++x){
        printf("%d ", arr[x]);
    }

    printf("\n\n");

    tournament_sort(arr, 12);

    for(x = 0; x < 12; ++x){
        printf("%d ", arr[x]);
    }


    return 0;
}