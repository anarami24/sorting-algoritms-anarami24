#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace SortingAlgorithms {

void bubbleSort(int arr[], int n) {
    
}

void selectionSort(int arr[], int n) {
    
}

void insertionSort(int arr[], int n) {
    
}

void merge(int arr[], int left, int mid, int right) {
    
}

void mergeSort(int arr[], int left, int right) {
    
}

int partition(int arr[], int low, int high) {
    
    return 0;
}

void quickSort(int arr[], int low, int high) {
    
}

void heapify(int arr[], int n, int i) {
    
}

void heapSort(int arr[], int n) {
    
}

void printArray(int arr[], int n) {
    if (n == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void SortingTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void SortingTimer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}

double SortingTimer::getElapsedMilliseconds() const {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count() / 1000.0;
}

std::string SortingTimer::getElapsedTime() const {
    double ms = getElapsedMilliseconds();
    std::stringstream ss;
    
    if (ms < 1.0) {
        ss << std::fixed << std::setprecision(3) << (ms * 1000) << " microseconds";
    } else if (ms < 1000.0) {
        ss << std::fixed << std::setprecision(3) << ms << " ms";
    } else {
        ss << std::fixed << std::setprecision(3) << (ms / 1000.0) << " seconds";
    }
    
    return ss.str();
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr = generateSortedArray(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    for (int i = 0; i < swaps && i < size/2; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

}