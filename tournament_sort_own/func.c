#include "def.h"

HEAP initHeap(int arr[], int count){
    HEAP retVal = {
        .lastNdx = 2 * count - 2
    };

    int x, y = 2 * count - 2;
    for(x = count - 1; x >= 0; ++x){
        retVal.tree[y--] = arr[x];
    }

    return retVal;
}

void tournament_sort(int arr[], int count){
    HEAP temp = createTree(arr, count);
    int x;

    arr[0] = removeChampion(&temp);
    for(x = 1; x < count; ++x){
        recreateTree(&temp);
    }


}

HEAP createTree(int arr[], int count){
    HEAP temp = initHeap(arr, count);
    int parentTrav;
    for(parentTrav = parent(temp.lastNdx); parentTrav >= 0; --parentTrav){
        temp.tree[parentTrav] = winner(temp, parentTrav, count);
    }
    
    return temp;
}

int parent(int childNdx){
    return (childNdx - 1) / 2;
}

int leftChild(int parentNdx){
    return (2 * parentNdx + 1);
}

int rightChild(int parentNdx){
    return (2 * parentNdx + 2);
}

int winner(HEAP heap, int parent, int count){
    int leftChild_trueNdx = (leftChild(parent) >= count - 1) ?  leftChild(parent) : heap.tree[leftChild(parent)];
    int rightChild_trueNdx = (rightChild(parent) >= count - 1) ?  rightChild(parent) : heap.tree[rightChild(parent)];
    int winner;

    if(heap.tree[leftChild_trueNdx] > heap.tree[rightChild_trueNdx]){
        winner = leftChild_trueNdx;
    } 
    else if(heap.tree[leftChild_trueNdx] < heap.tree[rightChild_trueNdx]){
        winner = rightChild_trueNdx;
    }
    else{
        winner = (leftChild_trueNdx < rightChild_trueNdx) ? leftChild_trueNdx : rightChild_trueNdx;
    }

    return winner;
}

int removeChampion(HEAP *ptr){
    int temp = ptr->tree[ptr->tree[0]];
    ptr->tree[ptr->tree[0]] = INF;

    return temp;
}

void recreateTree(HEAP *ptr){
    
}