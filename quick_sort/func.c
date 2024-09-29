#include "def.h"

void quick_sort(int arr[], int startNdx, int lastNdx){
    if(startNdx < lastNdx){
        //int pivot = lomuto_partition(arr, startNdx, lastNdx);
        int pivot = hoare_partition(arr, startNdx, lastNdx);
        quick_sort(arr, startNdx, pivot - 1);
        quick_sort(arr, pivot + 1, lastNdx);
    }
}

int lomuto_partition(int arr[], int startNdx, int lastNdx){
    int pivot = arr[lastNdx],
        lowBndry = startNdx - 1, 
        highBndry;

    for(highBndry = startNdx; highBndry < lastNdx; ++highBndry){
        if(arr[highBndry] <= pivot){
            ++lowBndry;
            swap(arr + highBndry, arr + lowBndry);
        }
        
    }
    //printf("%d", pivot);
    swap(arr + lastNdx, arr + lowBndry + 1);
    return lowBndry + 1;
}

int hoare_partition(int arr[], int startNdx, int lastNdx){
    int tempPivot = arr[startNdx],
        lowBndry = startNdx - 1,
        highBndry = lastNdx + 1;

    while(1){
        do{
            ++lowBndry;
        } while(arr[lowBndry] < tempPivot);

        do{
            --highBndry;
        } while(arr[highBndry] > tempPivot);

        if(lowBndry < highBndry) swap(arr + lowBndry, arr + highBndry);
        else return highBndry;
    }

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}