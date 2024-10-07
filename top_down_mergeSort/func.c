#include <stdlib.h>
#include "def.h"

void top_down_mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2; 

        top_down_mergeSort(arr, left, mid); // sort left sub-array
        top_down_mergeSort(arr, mid + 1, right); // sort right sub-array

        merge(arr, left, right); 
    }
}

void merge(int arr[], int left, int right){
    int trav, travL, travR;
    int mid = (left + right) / 2; 
    int arrLeftCount = mid - left + 1, 
        *arrLeft = (int*) malloc(sizeof(int) * arrLeftCount);
    int arrRightCount = right - mid, 
        *arrRight = (int*) malloc(sizeof(int) * arrRightCount);

    if(arrLeft != NULL && arrRight != NULL){ 
        for(travL = 0, trav = left; trav <= mid; ++trav, ++travL){
            arrLeft[travL] = arr[trav];
        }        
        for(travR = 0; trav <= right; ++trav, ++travR){
            arrRight[travR] = arr[trav];
        } 

        for(travL = travR = 0, trav = left; travL < arrLeftCount && travR < arrRightCount; ++trav){
            if(arrLeft[travL] > arrRight[travR]){
                arr[trav] = arrRight[travR];
                ++travR;
            }
            else{
                arr[trav] = arrLeft[travL];
                ++travL;
            }
        }

        for(; travL < arrLeftCount; ++travL, ++trav){
            arr[trav] = arrLeft[travL];
        }
        for(; travR < arrRightCount; ++travR, ++trav){
            arr[trav] = arrRight[travR];
        }

        free(arrLeft);
        free(arrRight);
    }
}