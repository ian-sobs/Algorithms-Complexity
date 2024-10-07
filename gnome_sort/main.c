#include "def.h"
#include "../def.h"

int main(){
    int arr[] = {9, 4, 0, 6, 10, -3, -7, 0, 9, 11, 9};
    int count = sizeof(arr) / sizeof(arr[0]);
    printList(arr, count);
    gnomeSort(arr, count);
    printList(arr, count);
    return 0;
}