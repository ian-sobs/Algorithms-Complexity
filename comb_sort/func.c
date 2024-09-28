#include "def.h"
#include<stdbool.h>

void comb_sort(int arr[], int count){//pushing down
    int y, gap, temp;
    bool swapped = true;

    for(gap = count / 1.3; gap != 1 || swapped; gap /= 1.3){
        if(gap < 1) gap = 1;
        swapped = false;
        for(y = count - 1; y >= gap; --y){
            if(arr[y] < arr[y - gap]){
                temp = arr[y];
                arr[y] = arr[y - gap];
                arr[y - gap] = temp;
                swapped = true;
            }
        }
    }
}