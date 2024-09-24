#include "def.h"
#include "../def.h"

int main(){
    int arr[15] = {-6, -39, 5, 7, 5, 7, 0, -1, 2, 99, 0, 1, 13, 44, 89};
    printList(arr, 15);
    bubble_sort(arr, 15);
    printList(arr, 15);
    return 0;
}