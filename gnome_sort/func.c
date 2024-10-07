#include "def.h"
#include <stdlib.h>

void gnomeSort(int arr[], int count){
    int x = 0;
    while(x < count){
        if(arr[x] > arr[x + 1]){
            swap(arr + x , arr + x + 1);
            if(x > 0){
                --x;
            }
        }
        else{
            ++x;
        }
    }
}

void swap(int *a, int *b){
    if(a != NULL && b != NULL){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}