//Reference code: https://en.oi-wiki.org/basic/tournament-sort/

#include "def.h"

void tournament_sort(int a[], int temp[], int count){
    int x , value;
    create_tree(a, temp, &value, count);
    for(x = 0; x < count; ++x){
        a[x] = value; 
        recreate(a, temp, count, &value);
    }
}

void create_tree(int a[], int temp[], int *value, int count){
    //array 'temp' will have a left and right subarray from indeces 0 to n-1a, nd n to 2*n - 1 respectively.
    //left subarray holds the indeces of elements in the right subarray who won the previous rounds. temp[1] is designated as the winner of the tournament.

    //let integer i b>= 0, then (2*n - 1) - 2*i represents the variable x after the i-th iteration of the for loop. When i == 0, x == floor((2*n - 1) / 2) == n - 1, the last element of the left subarray. 
    
    //When i == 1, x == floor((2*n - 1 - 2) / 2) == floor((2*n - 3) / 2) == n - 2
    
    // When i == m, m > 1, x == floor((2*n - 1 - 2*m) / 2) == n - m - 1

    // To prove that every index in the left subarray that is > 1 will have its preceding index filled after the i-th iteration, we have the proof below.

    // Case 1: x == floor((2*n - 1 - 2*(m+1)) / 2) == ((2*n - 1 - 2*m - 2) / 2) - (1/2) == (2*n - 4 - 2*m) / 2 == n - m - 2
    // Case 2: x == floor((2*n - 1 - 2*m) / 2) - 1 == n - m - 2

    // Hence, every index in the left subarray > 1 will have its preceding index "filled" after the i-th iteration.

    //NOTE: CODE BELOW WORKS ONLY IF THERE IS MORE THAN 1 ELEMENT IN THE ARRAY
    int x, y, k;
    for(x = 0; x < count; ++x) temp[count + x] = a[x];
    for(x = 2 * count - 1; x > 1; x -= 2){
        temp[x / 2] = winner(temp, count, x, x - 1);
    }
    *value = temp[temp[1]];
    temp[temp[1]] = INF;
}

void recreate(int a[], int temp[], int count, int *value){
    int x = temp[1], k;
    for(; x > 1; x = k){
        k = x / 2;
        if(x % 2 == 0) temp[k] = winner(temp, count, x, x + 1);
        else temp[k] = winner(temp, count, x, x - 1);
    }
    *value = temp[temp[1]];
    temp[temp[1]] = INF;
}

int winner(int temp[], int count, int ndx1, int ndx2){
    int u = (ndx1 >= count) ? ndx1 : temp[ndx1];
    int v = (ndx2 >= count) ? ndx2 : temp[ndx2];
    return (temp[u] <= temp[v]) ? u : v;
}

void display(int a[], int count){
    int x;
    for(x = 0; x < count; ++x){
        printf("%d", a[x]);
        if(x != count - 1) printf(" , ");
    }
    printf("\n\n");
}