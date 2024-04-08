#include <iostream>
#include <vector>

int comparisons = 0;
int swaps = 0; 

bool compare(int a, int b) {
    comparisons++;
    return a > b;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && compare(arr[j], key)) {
            swap(&arr[j + 1], &arr[j]);
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;

    int arr[n];
    
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);

    std::cout << "swaps: " << swaps << std::endl;
    std::cout << "comparisons: " << comparisons << std::endl;

    return 0;
}