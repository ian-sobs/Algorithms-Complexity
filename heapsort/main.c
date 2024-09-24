#include<stdio.h>
#include "def.h"

int main(){
    HEAP heap = {
        {99, 67, 81, 32, 0, -9, -9, 41, -41, 56, -42, 41},
        11
    };

    displayHeap(heap);
    heapsort(&heap);

    printf("\n\n");
    displayHeap(heap);

    return 0;
}