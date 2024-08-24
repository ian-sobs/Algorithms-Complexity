//Reference code: https://en.oi-wiki.org/basic/tournament-sort/

#define SIZE 15
#define MAX_SIZE SIZE*2
#define INF 9999
#include <stdio.h>

void tournament_sort(int a[], int temp[], int count);
int winner(int temp[], int count, int ndx1, int ndx2);
void create_tree(int a[], int temp[], int *value, int count);
void recreate(int a[], int temp[], int count, int *value);
void display(int a[], int count);
