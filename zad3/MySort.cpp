#include <iostream>
#include <fstream>

int comparisons = 0;
int swaps = 0; 
int RUN = 6;

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

void insertionSort(int arr[], int start, int end){
    int i, key, j;
    for (i = start + 1; i <= end; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= start && compare(arr[j], key)) {
            swap(&arr[j + 1], &arr[j]);
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

void mySort(int arr[], int n){
    for (int i = 0; i < n; i += RUN){
        insertionSort(arr, i, std::min((i + RUN - 1), (n - 1))); 
    }
    for (int size = RUN; size < n; size = 2 * size){ 
        for (int left = 0; left < n; left += 2 * size){ 
            int mid = left + size - 1; 
            int right = std::min((left + 2 * size - 1), (n - 1)); 
            if (mid < right){
                merge(arr, left, mid, right);
            } 
        } 
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
    std::ofstream outputFile("mysort_data.txt", std::ios_base::app);
    int n;
    std::cin >> n;

    int arr[n];
    int arr_copy[n];
    
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        arr_copy[i] = arr[i];
    }

    mySort(arr, n);
    if(n<40){
        std::cout << "input: " << std::endl;
        printArray(arr_copy, n);
        std::cout << "output: " << std::endl;
        printArray(arr, n);
    }
    outputFile << n << " " << swaps << " " << comparisons << std::endl;
    outputFile.close();
    std::cout << "swaps: " << swaps << std::endl;
    std::cout << "comparisons: " << comparisons << std::endl;
    is_sorted(arr, n);

    return 0;
}