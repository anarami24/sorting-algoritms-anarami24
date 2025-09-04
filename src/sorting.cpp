#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

namespace SortingAlgorithms {

void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1;i++){
        for (int j=0; j<n-1;j++){
          if (arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
          }
        }
      }
      

}

void selectionSort(int arr[], int n) {
    int temp, indexSmaller;
      for (int i=0; i<n-1;i++){
        indexSmaller=i;
        for (int j=i; j<n;j++){
          if (arr[j]<arr[indexSmaller]){
            indexSmaller=j;
          }
        }
        if (indexSmaller!=i){
          temp=arr[i];
          arr[i]=arr[indexSmaller];
          arr[indexSmaller]=temp;

        }

      }
      
}


void insertionSort(int arr[], int n) {
        int m, insert;
    for(int i=1;i<n;i++){
      insert=arr[i];
      m=i-1;
        while(m>=0 && arr[m]>insert){
          arr[m+1]=arr[m];
          m--;
        }
      arr[m+1]=insert;
    }
    
}

void merge(int arr[], int left, int mid, int right) {
  int p1=mid-left+1;
  int p2=right-mid;
  int Left[p1];
  int Right[p2];

  for (int i=0; i<p1;i++){
    Left[i]=arr[left+i];
  }
  for (int j=0; j<p2;j++){
    Right[j]=arr[j+1+mid];
  }
  int i=0, j=0, count=left;

  while (i<p1 && j<p2){
    if (Left[i]<=Right[j]){
      arr[count]=Left[i];
      i++;
    }
    else{
      arr[count]=Right[j];
      j++;
    }
    count++;

  }

  //if there are any elements missing
  while (i<p1){
    arr[count]=Left[i];
    i++;
    count++;
  }
  while (j<p2){
    arr[count]=Right[j];
    j++;
    count++;
  }
  

}

void mergeSort(int arr[], int left, int right) {
    
  if (left>=right){return;}
  int medium=left+(right-left)/2; //we find the middle
  mergeSort(arr, left,medium); //we call merge sort again to sort the left side
  //we call merge sort again to sort the right side
  mergeSort(arr,medium+1,right);
  //now we merge
  merge(arr,left, medium, right);
  
}

int partition(int arr[], int low, int high) {
    int pivot=arr[high];
    int j=low-1, temp;

    for (int i=low; i<=high-1;i++ ){
      if (arr[i]<pivot){
        j++;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        
      }
    }
    
    int index=j+1;
    
    arr[high]=arr[index];
    arr[index]=pivot;

    return index;
}

void quickSort(int arr[], int low, int high) {
  if (low>=high){return;} 
  int pivot= partition(arr,low,high);
  quickSort(arr,low, pivot-1);
  quickSort(arr,pivot+1,high);

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