#include "def.h"
#include "../def.h"

int main(){
    int arr[] = {1, 0, 5, 4, 3, 7, 9, 8, 1, 4, 3};
    int count = sizeof(arr)/sizeof(arr[0]);

    NODE list = initializeList(arr, count);
    printList(arr, count);
    strandSort(&list);
    displayLinkedList(list);
    deleteLinkedList(&list);
    return 0;
}