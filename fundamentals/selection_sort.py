#!/usr/bin/env python3
import random

def find_index_of_min(arr, start):
    min_element = arr[start]
    min_index = start

    for index in range(start + 1, len(arr)):
        if arr[index] < min_element:
            min_element = arr[index]
            min_index = index

    return min_index

def swap(arr, first, second):
    temp  = arr[first]
    arr[first]  = arr[second]
    arr[second] = temp

def selection_sort(arr):
    for index in range(len(arr)):
        min_index = find_index_of_min(arr, index)
        if min_index != index:
            swap(arr, index, min_index)
    
    return arr

def main():
    arr = [random.randrange(101) for _ in range(101)]
    print(arr)
    
    result = selection_sort(arr)
    print(result)

if __name__ == "__main__":
    main()