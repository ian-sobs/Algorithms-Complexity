#include "def.h"
#include <stdlib.h>

void tournamentSort_online(int arr[], int count){
    HEAP heap = createHeap(4);
    if(heap.tree != NULL){
        SET competitors = ~0;
        int x , y, winnerNdx, temp, *subArrBndry, subArrBndryCount, bndryCurr, arrCurrElem = 0;
        
        //subArrBndry array contains the ending index of the sub-arrays we have to merge. This array is needed so that you can partition the original array and those partitions/sub-arrays can be merged 
        subArrBndryCount = (!(count % (heap.lastNdx + 1))) ? 0 : 1;
        subArrBndryCount += (count / (heap.lastNdx + 1));
        subArrBndry = (int*) calloc(subArrBndryCount, sizeof(int));

        if(subArrBndry != NULL){
            //initializing the tree by putting values to its leaf nodes
            //try implementing lines 23-42 as a recursive function that takes into account the allowed competitors for a tournament
            for(x = 0, y = parent(heap.lastNdx) + 1; y <= heap.lastNdx && arrCurrElem < count; ++y){
                heap.tree[y] = arr[arrCurrElem++];
            }

            //filling up the tree with values where no champion has been found yet
            for(x =  parent(heap.lastNdx); x >= 0; --x){
                y = promoteElems(heap, x, competitors); // y here is the index of the leaf node where we insert a new element from the given array
                heap.tree[y] = (arrCurrElem < count) ? arr[arrCurrElem++] : EMPTY;
                partiallyOrder(heap, y, x);
            }

            for(bndryCurr = 0; bndryCurr < subArrBndryCount && arrCurrElem < count; ++bndryCurr, subArrBndry[bndryCurr] = subArrBndry[bndryCurr - 1] + 1){
                // recursion might be needed after the for-loop below and the for-loop above might not be necessary
                for(; heap.tree[0] < EMPTY; ++(subArrBndry[bndryCurr])){
                    arr[subArrBndry[bndryCurr]] = returnChampion(heap); //next element in subArrBndry which is set to 0.
                    y = promoteElems(heap, 0, competitors); // 'y' may not be a leaf node if both children of an i-node cannot compete

                    heap.tree[y] = (arrCurrElem < count && leftChild(y) > heap.lastNdx) ? arr[arrCurrElem++] : EMPTY; // condition guarantees that new elements can only be inserted in a leaf node (assuming not all elements in given array have been inserted)

                    if(arr[subArrBndry[bndryCurr]] > heap.tree[y]){
                       competitors &= (~(1 << (y - (parent(heap.lastNdx) + 1))));
                    }
                    else{
                        partiallyOrder(heap, y, 0);
                    }
                }
            }

        }
    }
}

void partiallyOrder(HEAP heap, int start, int end){
    if(end >= 0){
        int trav, temp;
        for(trav = start, temp = heap.tree[start]; trav > end && temp != EMPTY && temp < heap.tree[parent(trav)]; trav = parent(trav)){
            heap.tree[trav] = heap.tree[parent(trav)];
        }
        heap.tree[trav] = temp;
    }
}

int promoteElems(HEAP heap, int hghstAvlblNode, SET competitors){
    int trav, winnerNdx;
    for(trav = hghstAvlblNode; (winnerNdx = winner(heap, leftChild(trav), rightChild(trav))) > 0 && (canCompete(competitors, leftChild(trav), heap.lastNdx) || canCompete(competitors, rightChild(trav), heap.lastNdx)); trav = winnerNdx){
        if(canCompete(competitors, leftChild(trav), heap.lastNdx) && !canCompete(competitors, rightChild(trav), heap.lastNdx)) winnerNdx = leftChild;
        else if(!canCompete(competitors, leftChild(trav), heap.lastNdx) && canCompete(competitors, rightChild(trav), heap.lastNdx)) winnerNdx = rightChild;
        heap.tree[trav] = heap.tree[winnerNdx];
    }
    if(winnerNdx > 0){// loop stopped because both children of node 'trav' could not compete
        heap.tree[trav] = EMPTY;
    }
    return trav;
}

int canCompete(SET competitors, int nodeNdx, int lastLeafNodeNdx){
    return competitors & (1 << (nodeNdx - (parent(lastLeafNodeNdx) + 1)));
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
    int winner = -1;
    if(leftChild <= minHeap.lastNdx){
        winner = leftChild;
        if(rightChild <= minHeap.lastNdx && minHeap.tree[leftChild] > minHeap.tree[rightChild]){
            winner = rightChild;
        }
    }
    return winner;
}

int returnChampion(HEAP heap){
    //int champion = heap.tree[0];
    //heap.tree[0] = winner(heap, leftChild(0), rightChild(0));
    return heap.tree[0];
}