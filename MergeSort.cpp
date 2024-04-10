#include <iostream>

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

void merge(int array[], int left, int mid, int right){
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
 
    int leftArray[subArrayOne], rightArray[subArrayTwo];
 
    for (int i = 0; i < subArrayOne; i++){
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
    }

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
 
    int indexOfMergedArray = left; 
 
    while (subArrayOne > indexOfSubArrayOne && subArrayTwo > indexOfSubArrayTwo){
        if (!compare(leftArray[indexOfSubArrayOne], rightArray[indexOfSubArrayTwo])){
            swap(&array[indexOfMergedArray], &leftArray[indexOfSubArrayOne]);
            indexOfSubArrayOne++;
        } else{
            swap(&array[indexOfMergedArray], &rightArray[indexOfSubArrayTwo]);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (subArrayOne > indexOfSubArrayOne){
        swap(&array[indexOfMergedArray], &leftArray[indexOfSubArrayOne]);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (subArrayTwo > indexOfSubArrayTwo){
        swap(&array[indexOfMergedArray], &rightArray[indexOfSubArrayTwo]);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int begin, int end){
    if (begin >= end)
        return; 
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
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

    mergeSort(arr, 0, n - 1);
    if(n<40){
        std::cout << "tablica wejsciowa: " << std::endl;
        printArray(arr_copy, n);
        std::cout << "tablica po sortowaniu: " << std::endl;
        printArray(arr, n);
    }

    std::cout << "swaps: " << swaps << std::endl;
    std::cout << "comparisons: " << comparisons << std::endl;
    is_sorted(arr, n);

    return 0;
}