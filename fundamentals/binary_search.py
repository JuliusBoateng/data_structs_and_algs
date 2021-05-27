#!/usr/bin/env python3
import time

def recursive_binary_search_helper(arr, left, right, start_time, count, target):
    if left > right:
        print(f"Searches: {count} Duration: {time.time() - start_time} s")
        return -1

    mid = (left + right) // 2
    guess = arr[mid]

    if target == guess:
        print(f"Searches: {count} Duration: {time.time() - start_time} s")
        return mid

    if target > guess:
        left =  mid + 1
    else:
        right = mid - 1
    
    return recursive_binary_search_helper(arr, left, right, start_time, count + 1, target)

def recursive_binary_search(arr, target):
    left =  0
    right = len(arr) - 1
    start_time = time.time()
    count = 1

    print("Recursive")
    result  = recursive_binary_search_helper(arr, 0, len(arr) - 1, start_time, count, target)
    print(f"Index: {result}")
    return result

def binary_search(arr, target):
    start_time = time.time()
    left = 0
    right = len(arr) - 1
    count = 1

    while left <= right:
        mid = (left + right) // 2
        guess = arr[mid]

        if target == guess:
            print(f"Searches: {count} Duration: {time.time() - start_time} s")
            print(f"Index: {mid}")
            return mid
        elif target > guess:
            left = mid + 1
        else:
            right = mid - 1
        
        count += 1

    print("Iterative")
    print(f"Searches: {count} Duration: {time.time() - start_time} s")
    print(f"Index: {-1}")
    return -1

def main():
    arr = list(range(1,100000001))
    target = 1

    recursive_binary_search(arr, 33)
    binary_search(arr, 33)

if __name__ == "__main__":
    main()