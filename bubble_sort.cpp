#include <iostream>

//adjacent elements is compared and the elements are swapped if they are not in order
void createArray(int* unsorted_arr, int length){
    for (int i = 0; i < length; i++){
        scanf("%d", &unsorted_arr[i]);
    }
}

void swap(int *arr, int index1, int index2){
    int temp = arr[index1];

    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubbleSort(int *arr, int length){
    bool sorted = false;

    while (!sorted){
        sorted = true;
        for (int i = 0; i < length - 1; i++){
            if (arr[i] > arr[i+1]){
                swap(arr,i,i+1);
                sorted = false;
            }
        }
    }
}

void printArray(int* arr, int length){
    for (int i = 0; i < length; i++){
        std::cout << arr[i] << std::endl;
    }
}

int main(){
    int length = 10;
    int arr[length];

    createArray(arr, length);
    bubbleSort(arr, length);
    printArray(arr,length);

    return 0;
}