#include <stdlib.h>
#include "def.h"

void counting_sort(int arr[], int num){
    // arr[] is the given array and num is the number of elements in that
	// array.

	int max = arr[0], min = arr[0], x;

	// finds the maximum and minimum element
	for(x = 1; x < num; ++x){
		if(max < arr[x]) max = arr[x];
		if(min > arr[x]) min = arr[x];
    }

    int size = max - min + 1;

    int *temp = (int*)malloc(sizeof(int) * num);
	int *count = (int*) calloc(size, sizeof(int));//allocate array `count` of size max - min + 1

    if(temp != NULL && count != NULL){
        for(x = 0; x < num; ++x){
            // Update the number of occurrences of an
            // element in `arr` stored in the `count` 
            // array
            count[arr[x] - min] = count[arr[x] - min] + 1;
        }
        for(x = 1; x < size; ++x){
            // find the number of occurrences of elements 
            // from min to x + min and store them at count[x]
            count[x] = count[x] + count[x - 1];
        }
        // place elements in `arr` in `temp` in ascending order
        for(x = num - 1; x >= 0; --x){
            count[arr[x] - min] = count[arr[x] - min] - 1;
            temp[count[arr[x] - min]] = arr[x];
        }
        // copy elements in `temp` to `arr`
        for(x = num - 1; x >= 0; --x){
            arr[x] = temp[x];
        }

        free(temp);
        free(count);
    }
}