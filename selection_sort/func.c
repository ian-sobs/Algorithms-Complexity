void selection_sort(int arr[], int count){
    int x, y, smallest, temp;
    for(x = 0; x < count - 1; ++x){
        smallest = x;
        for(y = x + 1; y < count; ++y){
            if(arr[smallest] > arr[y]){
                smallest = y;
            }
        }
        temp = arr[x];
        arr[x] = arr[smallest];
        arr[smallest] = temp;
    }
}