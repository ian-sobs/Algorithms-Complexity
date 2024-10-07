#include "def.h"
#include "../def.h"

int main(){
    int arr[] = {5, 3, -2, 9, 9, 5, 32, 15, 0};
    printList(arr, 9);
    top_down_mergeSort(arr, 0, 8);
    printList(arr, 9);
    return 0;
}