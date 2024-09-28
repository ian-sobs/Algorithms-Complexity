#include "../def.h"
#include "def.h"

int main(){
    int arr[11] = {5, 7, -1, -5, 7, 5, 3, 11, 9, 4, -11};
    printList(arr, 11);
    comb_sort(arr, 11);
    printList(arr, 11);
    return 0;
}