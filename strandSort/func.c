#include "def.h"
#include <stdio.h>
#include <stdlib.h>


NODE strandSort(NODE *list){
    NODE mergedList = NULL;
    if(*list != NULL){
        NODE sublist, *travG, *travS, temp;

        // First element of the given list is put into an empty sublist 
        travS = &sublist;
        sublist = *list;
        if(sublist != NULL){
            *list = (*list)->link;
            sublist->link = NULL;
        }
        //travS = &(*travS)->link;
        // *list now points to the second element in the list

        // for loop doesnt execute if *travG is empty list
        // sublist guaranteed to have at least 1 element
        for(travG = list; *travG != NULL; travG = &(*travG)->link){
            // if the last element in the sublist is less than an element in the given list, that element in the given list in inserted as a last element in the sublist. That element is also no longer in the given list.
            if((*travG)->data > (*travS)->data){ 
                travS = &(*travS)->link;
                *travS = *travG;
                
                *travG = (*travG)->link;

                (*travS)->link = NULL;
            }
        }
        printf("sublist:");
        displayLinkedList(sublist);
        printf("list:");
        displayLinkedList(*list);
        printf("mergedlist:");
        mergedList = strandSort(list); // problem
        displayLinkedList(mergedList);
        merge(&mergedList, &sublist); // problem
    }
    return mergedList;
}

void merge(NODE *mergedList, NODE *subList){
    NODE temp = *mergedList, *trav = mergedList, *travS, *travT;

    *mergedList = NULL; // initialized the merged list to be empty because its previous content will be merged with the given sublist
    printf("\n\ntrt\n\n");
    displayLinkedList(*subList);
    for(travS = subList, travT = &temp; *travS != NULL && *travT != NULL; ){
        // removes the node from the list *travS and inserts it to the merged list.
        if((*travT)->data > (*travS)->data){
            *trav = *travS;
            //printf("%d ", (*trav)->data);
            trav = &(*trav)->link;
            *travS = *trav;
            *trav = NULL;
        }
        else{
            *trav = *travT;
            //printf("%d ", (*trav)->data);
            trav = &(*trav)->link;
            *travT = *trav;
            *trav = NULL;            
        }
    }

    if(*travS != NULL){
        *trav = *travS;
        *travS = NULL;
    }
    else{
        *trav = *travT;
        *travT = NULL;
    }

}

NODE initializeList(int arr[], int count){
    int x;
    NODE list, *trav;
    for(x = 0, trav = &list; x < count; ++x){
        *trav = (NODE) malloc(sizeof(NODE_TYPE));
        if(*trav != NULL){
            (*trav)->data = arr[x];
            trav = &(*trav)->link;
        }
    }
    *trav = NULL;
    return list;
}

void displayLinkedList(NODE list){
    NODE trav;
    for(trav = list; trav != NULL; trav = trav->link){
        printf("%d ", trav->data);
    }
    printf("\n\n");
}

void deleteLinkedList(NODE *list){
    NODE *trav, temp;
    for(trav = list; *trav != NULL; ){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}