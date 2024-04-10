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

std::pair<int, int> partition(int* arr, int low, int high){ 
    if (compare(arr[low], arr[high])){
        swap(&arr[low], &arr[high]); 
    }

    int j = low + 1; 
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high]; 
    while (k <= g) { 
        if (compare(p, arr[k])) { 
            swap(&arr[k], &arr[j]); 
            j++; 
        } else if (!compare(q, arr[k])) { 
            while (compare(arr[g], q) && g > k){
                g--; 
            }
            swap(&arr[k], &arr[g]); 
            g--; 
            if (compare(p, arr[k])) { 
                swap(&arr[k], &arr[j]); 
                j++; 
            } 
        } 
        k++; 
    } 
    j--; 
    g++; 
  
    swap(&arr[low], &arr[j]); 
    swap(&arr[high], &arr[g]); 
  
    return std::make_pair(j, g); 
} 
 
void dual_pivot_qs(int arr[], int start, int end ){
    if (start >= end)
        return;
    std::pair<int, int> p = partition(arr, start, end);
    int left_pivot = p.first;
    int right_pivot = p.second;
    dual_pivot_qs(arr, start, left_pivot - 1);
    dual_pivot_qs(arr, left_pivot + 1, right_pivot - 1);
    dual_pivot_qs(arr, right_pivot + 1, end);
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
    int n;
    std::cin >> n;

    int arr[n];
    int arr_copy[n];
    
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        arr_copy[i] = arr[i];
    }

    dual_pivot_qs(arr, 0, n - 1);
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