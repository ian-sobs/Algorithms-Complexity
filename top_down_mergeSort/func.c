#include <stdlib.h>
#include "def.h"
void top_down_mergeSort(int arr[], int left, int right){
    if(left < right){
        int trav, travL, travR;
        int mid = (left + right) / 2; 
        int arrLeftCount = mid - left + 1, 
            *arrLeft = (int*) malloc(sizeof(int) * arrLeftCount);
        int arrRightCount = right - mid, 
            *arrRight = (int*) malloc(sizeof(int) * arrRightCount);

        if(arrLeft != NULL && arrRight != NULL){
            for(travL = 0, trav = left; trav <= mid; ++trav){
                arrLeft[travL] = arr[trav];
            }        
            for(travR = 0; trav <= right; ++trav){
                arrRight[travR] = arr[trav];
            } 

            top_down_mergeSort(arrLeft, 0, arrLeftCount - 1); // sort left sub-array
            top_down_mergeSort(arrRight, 0, arrRightCount - 1); // sort right sub-array

            // using the left and right sub-arrays to sort arr[]
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

            for(; travL < arrLeftCount; ++travL){
                arr[trav] = arrLeft[travL];
            }
            for(; travR < arrRightCount; ++travR){
                arr[trav] = arrRight[travR];
            }
        }   
    }
}