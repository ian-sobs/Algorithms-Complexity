#include "def.h"
#include <stdlib.h>

void strandSort(NODE *list){
    if(*list != NULL){
        NODE sublist, mergedList, *travG, *travS;

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
                if((*travG)->link != NULL){
                    *travG = (*travG)->link->link;
                } 
                else{
                    *travG = NULL;
                }
                (*travS)->link = NULL;
            }
        }

        merge(mergedList, sublist);
        strandSort(list);
    }
}

void merge(NODE mergedList, NODE subList){
    NODE temp = mergedList, *trav = &mergedList, *travS, *travT;

    mergedList = NULL; // initialized the merged list to be empty because its previous content will be merged with the given sublist
    for(travS = &subList, travT = &temp; *travS != NULL && *travT != NULL; ){
        // removes the node from the list *travS and inserts it to the merged list.
        if((*travT)->data > (*travS)->data){
            *trav = *travS;
            trav = &(*trav)->link;
            *travS = *trav;
            *trav = NULL;
        }
        else{
            *trav = *travT;
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

    return list;
}