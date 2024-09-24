#define SIZE 25

typedef struct{
    int tree[SIZE], lastNdx;
} HEAP;

void initHeap(HEAP *heap);
void heapsort(HEAP *heap);
void heapify();
void deleteMin();
void displayHeap(HEAP heap);
void pushDown(HEAP *heap, int startFrom);