#define SIZE 51
#define INF 9999

typedef struct{
    int tree[SIZE], lastNdx;
} HEAP;

void tournament_sort(int arr[], int count);
int parent(int childNdx);
int leftChild(int parentNdx);
int rightChild(int parentNdx);
int winner(HEAP heap, int parent, int count);
int removeChampion(HEAP *ptr);
void recreateTree(HEAP *ptr, int count);
HEAP createTree(int arr[], int count);