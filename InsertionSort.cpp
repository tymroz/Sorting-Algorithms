#include <iostream>
#include <fstream>

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

void insertionSort(int arr[], int n){
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
 
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++){
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
    std::ofstream outputFile("insertion_data.txt", std::ios_base::app);
    int n;
    std::cin >> n;

    int arr[n];
    int arr_copy[n];
    
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        arr_copy[i] = arr[i];
    }

    insertionSort(arr, n);
    if(n<40){
        std::cout << "input: " << std::endl;
        printArray(arr_copy, n);
        std::cout << "output: " << std::endl;
        printArray(arr, n);
    }
    outputFile << /*n << " " <<*/ swaps << " " << comparisons << std::endl;
    outputFile.close();
    std::cout << "swaps: " << swaps << std::endl;
    std::cout << "comparisons: " << comparisons << std::endl;
    is_sorted(arr, n);

    return 0;
}