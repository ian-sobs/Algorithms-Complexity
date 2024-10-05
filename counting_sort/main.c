#include "../def.h"
#include "def.h"

int main(){
    int arr[] = {79, 78, 87, 81, 80, 81, 79, 78, 82};
    printList(arr, 9);
    counting_sort(arr, 9);
    printList(arr, 9);
    return 0;
}