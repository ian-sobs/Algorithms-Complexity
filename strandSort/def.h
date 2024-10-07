typedef struct node{
    int data;
    struct node *link;
} *NODE, NODE_TYPE;

void strandSort(NODE *list);
NODE initializeList(int arr[], int count);