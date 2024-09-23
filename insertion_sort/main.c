#include "../def.h"
#include "def.h"

int main(){
    int arr[SIZE] = {11, -32, -64, -32, 0, 1, 3, 8, 9, 9, 1, 2, 5, 7};
    int count = 14;

    printList(arr, count);
    insertion_sort(arr, count);
    printList(arr, count);
    return 0;
}