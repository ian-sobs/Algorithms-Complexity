#include "def.h"

// void quick_sort(int arr[], int startNdx, int lastNdx){
//     if(startNdx < lastNdx){
//         int pivot = lomuto_partition(arr, startNdx, lastNdx);
//         quick_sort(arr, startNdx, pivot - 1);
//         quick_sort(arr, pivot + 1, lastNdx);
//     }
// }

void quick_sort(int arr[], int startNdx, int lastNdx){
    if(startNdx < lastNdx){
        int pivot = hoare_partition(arr, startNdx, lastNdx);
        quick_sort(arr, startNdx, pivot);
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

    while(lowBndry < highBndry){
        do{
            ++lowBndry;
        } while(arr[lowBndry] < tempPivot);

        do{
            --highBndry;
        } while(arr[highBndry] > tempPivot);

        if(lowBndry < highBndry) swap(arr + lowBndry, arr + highBndry);
        
    }
    return highBndry;
    // while (1) {
      
    //     // Find leftmost element greater
    //     // than or equal to pivot
    //     do {
    //         lowBndry++;
    //     } while (arr[lowBndry] < tempPivot);

    //     // Find rightmost element smaller 
    //     // than or equal to pivot
    //     do {
    //         highBndry--;
    //     } while (arr[highBndry] > tempPivot);

    //     // If two pointers met
    //     if (lowBndry >= highBndry)
    //         return highBndry;

    //     // Swap arr[i] and arr[j]
    //     int temp = arr[lowBndry];
    //     arr[lowBndry] = arr[highBndry];
    //     arr[highBndry] = temp;
    // }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}