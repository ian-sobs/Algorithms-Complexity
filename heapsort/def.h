#define SIZE 25

typedef struct{
    int tree[SIZE], lastNdx;
} HEAP;


int parent(int childNdx);
int leftChild(int parentNdx);
int rightChild(int parentNdx);
void heapsort(HEAP *heap);
void heapify(HEAP *heap);
int deleteMin(HEAP *heap);
void pushDown(HEAP *heap, int startFrom);
void displayHeap(HEAP heap);