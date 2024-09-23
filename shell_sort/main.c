#include "def.h"

int main(){
    int arr[SIZE] = {10, 8, -2, 5, 31, 8, 5, 1, 2, 3, 7};
    int count = 11;
    
    printList(arr, count);
    shell_sort(arr, count);
    printList(arr, count);
    return 0;
}