#include "def.h"
#include <stdio.h>

int parent(int childNdx){
    return (childNdx - 1) / 2;
}

int leftChild(int parentNdx){
    return 2 * parentNdx + 1;
}

int rightChild(int parentNdx){
    return 2 * parentNdx + 2;
}

void heapsort(HEAP *heap){
    int insertDeleted, actualHeapSize;
    insertDeleted = actualHeapSize = heap->lastNdx;

    heapify(heap);
    while(heap->lastNdx > 0){
        heap->tree[insertDeleted--] = deleteMin(heap);
    }

    heap->lastNdx = actualHeapSize;
}

void heapify(HEAP *heap){
    int x;
    for(x = parent(heap->lastNdx); x >= 0; --x){
        pushDown(heap, x);
    }
}

int deleteMin(HEAP *heap){
    int rootElem;
    
    rootElem = heap->tree[0];
    heap->tree[0] = heap->tree[heap->lastNdx];
    --(heap->lastNdx);
    
    pushDown(heap, 0);

    return rootElem;
}

void pushDown(HEAP *heap, int startFrom){
    int boundary = parent(heap->lastNdx), 
        trav, 
        temp = heap->tree[startFrom], 
        swapWith;

    for(trav = startFrom; trav <= boundary && (temp > heap->tree[leftChild(trav)] || (rightChild(trav) <= heap->lastNdx && temp > heap->tree[rightChild(trav)]));){

        if(rightChild(trav) <= heap->lastNdx && heap->tree[leftChild(trav)] > heap->tree[rightChild(trav)]){
            swapWith = rightChild(trav);
        }
        else{
            swapWith = leftChild(trav);
        }
        
        // if(heap->tree[leftChild(trav)] <= heap->tree[rightChild(trav)]){
        //     swapWith = leftChild(trav);
        // }
        // else{
        //     swapWith = rightChild(trav);
        // }

        if(heap->tree[swapWith] < temp){
            heap->tree[trav] = heap->tree[swapWith];
            trav = swapWith;
        }
    }
    heap->tree[trav] = temp;
}

void displayHeap(HEAP heap){
    int x;

    for(x = 0; x <= heap.lastNdx; ++x){
        printf("%d ", heap.tree[x]);
    }
}
