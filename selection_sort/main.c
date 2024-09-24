#include "../def.h"
#include "def.h"

int main(){
    int arr[] = {7, -13, -5, -20, 5, 0, 11, 1, 1, -13, -5, 99, 47};

    printList(arr, 13);
    selection_sort(arr, 13);
    printList(arr, 13);

    return 0;
}