#include "def.h"
#include "../def.h"

int main(){
    int arr[12] = {8, -1, 0, 5, 7, 6, 7, 4, -3, -1, 11, -20};
    printList(arr, 12);
    quick_sort(arr, 0, 11);
    printList(arr, 12);
    return 0;
}