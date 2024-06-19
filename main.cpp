#include "mergesort.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int arraySize = 1000;
    const int testRuns = 10;
    const int elementToFind = 500; // Example element to find
    std::srand(std::time(nullptr));

    // Generate a large array with more than 1000 elements
    std::vector<int> arr(arraySize);
    for (int& val : arr) {
        val = std::rand();
    }

    std::vector<int> arrCopy = arr;

    // Measure time for merge sort
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < testRuns; ++i) {
        arr = arrCopy;
        mergeSort(arr);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    double avgTimeSort = duration.count() / testRuns;

    std::cout << "Average time for merge sort: " << avgTimeSort << " seconds." << std::endl;

    // Sort the array once for searching
    mergeSort(arrCopy);

    // Measure time to find a specific element
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < testRuns; ++i) {
        findElement(arrCopy, elementToFind);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    double avgTimeFind = duration.count() / testRuns;

    std::cout << "Average time to find element " << elementToFind << ": " << avgTimeFind << " seconds." << std::endl;

    // Test with an array of 50 elements
    const int smallArraySize = 50;
    std::vector<int> smallArr(smallArraySize);
    for (int& val : smallArr) {
        val = std::rand() % 100; // smaller range for clarity in the example
    }

    std::cout << "Input array of 50 elements:" << std::endl;
    printArray(smallArr);

    // Sort the small array and print results
    mergeSort(smallArr);
    std::cout << "Sorted array of 50 elements:" << std::endl;
    printArray(smallArr);

    return 0;
}
