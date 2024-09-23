#include<stdio.h>
void printList(int arr[], int size){
    int x;
    for(x = 0; x < size; ++x){
        printf("%d ", arr[x]);
    }
    printf("\n\n");
}