#include <iostream>

const int INSERTION_SORT_THRESHOLD = 5;

int comparisons = 0;
int swaps = 0; 

bool compare(int a, int b){
    comparisons++;
    return a > b;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    int pivotIndex = start + count;
    swap(&arr[pivotIndex], &arr[start]);
 
    int i = start, j = end;
 
     while (pivotIndex > i && j > pivotIndex) {
        while (!compare(arr[i], pivot)) {
            i++;
        }
        while (compare(arr[j], pivot)) {
            j--;
        }
        if (pivotIndex > i && j > pivotIndex) {
            swap(&arr[i++], &arr[j--]);
        }
    }
    return pivotIndex;
}
 
void insertionSort(int arr[], int start, int end){
    int i, key, j;
    for (i = start + 1; i <= end; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && compare(arr[j], key)) {
            swap(&arr[j + 1], &arr[j]);
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int start, int end ){
    if (start >= end)
        return;
    if (end - start <= INSERTION_SORT_THRESHOLD){
        insertionSort(arr, start, end);
    } else {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

void hybrid(int arr[],int n){
    quickSort(arr, 0, n - 1);
}

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        if(arr[i] < 10){
            std::cout << "0" << arr[i] << " ";
        } else{
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

bool is_sorted(int arr[],int n){
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            std::cout << "is NOT correctly sorted" << std::endl;
            return false;
        }
    }
    std::cout << "is correctly sorted" << std::endl;
    return true;
}

int main(){
    int n;
    std::cin >> n;

    int arr[n];
    int arr_copy[n];
    
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        arr_copy[i] = arr[i];
    }

    hybrid(arr, n);
    if(n<40){
        std::cout << "input: " << std::endl;
        printArray(arr_copy, n);
        std::cout << "output: " << std::endl;
        printArray(arr, n);
    }

    std::cout << "swaps: " << swaps << std::endl;
    std::cout << "comparisons: " << comparisons << std::endl;  
    is_sorted(arr, n);

    return 0;
}