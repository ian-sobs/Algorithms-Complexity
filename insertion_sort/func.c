void insertion_sort(int arr[], int count){
    int x, y, temp;
    for(x = 1; x < count; ++x){
        temp = arr[x];
        for(y = x; y > 0 && arr[y - 1] > temp; --y){
            arr[y] = arr[y - 1];
        }
        arr[y] = temp;
    }
}