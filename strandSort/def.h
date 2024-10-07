typedef struct node{
    int data;
    struct node *link;
} *NODE, NODE_TYPE;

void strandSort(NODE *list);
void merge(NODE mergedList, NODE subList);

NODE initializeList(int arr[], int count);
void displayLinkedList(NODE list);

void deleteLinkedList(NODE *list);