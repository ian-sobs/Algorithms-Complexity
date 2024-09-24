void bubble_sort(int arr[], int count){
    int x, y, temp;
    for(x = count - 1; x > 1; --count){
        for(y = 0; y < x; ++y){
            if(arr[y] > arr[y + 1]){
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }
}