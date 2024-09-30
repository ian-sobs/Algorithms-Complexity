#include "def.h"
#include <stdlib.h>

void tournamentSort_online(int arr[], int count){
    HEAP heap = createHeap(4);
    int x , y, winnerNdx, arrCurrElem = 0, temp;

    for(x = count - 1, y = heap.lastNdx; x >= 0; --x){
        heap.tree[y--] = arr[x];
    }

    for(x =  parent(heap.lastNdx); x >= 0; --x){
        for(y = x; leftChild(y) <= heap.lastNdx; y = winnerNdx){
            winnerNdx = (rightChild(y) <= heap.lastNdx) ? winner(heap, leftChild(y), rightChild(y)) : leftChild(y);
            heap.tree[y] = heap.tree[winnerNdx];
        }
        temp = heap.tree[y] = (arrCurrElem < count) ? arr[arrCurrElem++] : EMPTY;
        for(; y > x && temp != EMPTY; y = parent(y)){
            heap.tree[y] = (heap.tree[parent(y)] > temp) ? heap.tree[parent(y)] : temp;
        }
    }
}

HEAP createHeap(int leafNodeCount){
    HEAP heap;
    heap.tree = (int*) malloc(sizeof(int) * (2 * leafNodeCount - 1));
    heap.lastNdx = 2 * leafNodeCount - 2;
    return heap;
}

int leftChild(int parent){
    return 2 * parent + 1;
}

int rightChild(int parent){
    return 2 * parent + 2;
}

int parent(int child){
    return (child - 1) / 2;
}

int winner(HEAP minHeap, int leftChild, int rightChild){
    int winner;
    if(minHeap.tree[leftChild] < minHeap.tree[rightChild]) winner = leftChild;
    else if(minHeap.tree[leftChild] > minHeap.tree[rightChild]) winner = rightChild;
    else if(leftChild < rightChild) winner = leftChild;
    else winner = rightChild;
    return winner;
}

int removeChampion(HEAP heap){
    int champion = heap.tree[0];
    heap.tree[0] = winner(heap, leftChild(0), rightChild(0));
    return champion;
}