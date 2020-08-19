#include <iostream>
#include <string>
#include <sstream>
#include <set>

//repeatedly finds the minimum element from the unsorted and puts it into the sorted array. 
int* createArray(int* unsorted_arr, int length){
    for (int i = 0; i < length; i++){
        scanf("%d", &unsorted_arr[i]);
    }

    return unsorted_arr;
}

int* selectionSort(int* unsorted_arr, int length, int* sorted_arr){
    std::set <int> indexes; 

    for (int x = 0; x < length; x++){
            int min = INT_MAX;
            int index = -1;
        for (int y = 0; y < length; y++){
            if (indexes.find(y) != indexes.end()){
                continue;
            }

            if (min >= unsorted_arr[y]){
                min = unsorted_arr[y];
                index = y;
            }
        }
        indexes.insert(index);
        sorted_arr[x] = min;
    }
    return sorted_arr;
}

void printArray(int* arr, int length){
    for (int i = 0; i < length; i++){
        std::cout << arr[i] << std::endl;
    }
}

int main(){
    int length = 10;
    int unsorted_arr[length];
    int sorted_arr[length];

    createArray(unsorted_arr, length);
    selectionSort(unsorted_arr, length, sorted_arr);
    printArray(sorted_arr, length);

    return 0;
}
        