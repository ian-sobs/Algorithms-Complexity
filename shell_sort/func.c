#include<stdio.h>

void shell_sort(int arr[], int size){ //implemented using shell's sequence
    int gap, x, y, temp;
    for(gap = size / 2; gap >= 1; gap /= 2){
        for(x = gap; x < size; ++x){
            temp = arr[x];
            for(y = x; y >= gap && arr[y - gap] > temp; y -= gap){
                arr[y] = arr[y - gap];
            }
            arr[y] = temp;
        }
    }
}

void printList(int arr[], int size){
    int x;
    for(x = 0; x < size; ++x){
        printf("%d ", arr[x]);
    }
}