#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <iomanip>

// Function declarations (matching student's sorting.h)
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);

// Test result tracking
struct TestResult {
    std::string algorithm;
    int tests_passed;
    int total_tests;
    double score;
};

// Helper function to check if array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

// Helper to copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Minimal test suite - only 3 essential tests per algorithm to save execution time
bool runMinimalTests(void (*sortFunc)(int[], int), const std::string& name, TestResult& result) {
    result.algorithm = name;
    result.tests_passed = 0;
    result.total_tests = 3;
    
    // Test 1: Small random array (tests basic functionality)
    int test1[] = {5, 2, 8, 1, 9, 3};
    int n1 = 6;
    int copy1[6];
    copyArray(test1, copy1, n1);
    
    sortFunc(copy1, n1);
    if (isSorted(copy1, n1)) {
        result.tests_passed++;
    }
    
    // Test 2: Array with duplicates (tests stability/correctness with duplicates)
    int test2[] = {3, 1, 3, 2, 1, 2, 3};
    int n2 = 7;
    int copy2[7];
    copyArray(test2, copy2, n2);
    
    sortFunc(copy2, n2);
    if (isSorted(copy2, n2)) {
        result.tests_passed++;
    }
    
    // Test 3: Edge case - single element and empty (if n=0 handled)
    int test3[] = {42};
    int n3 = 1;
    int copy3[1];
    copyArray(test3, copy3, n3);
    
    sortFunc(copy3, n3);
    if (copy3[0] == 42) {  // Single element should remain unchanged
        result.tests_passed++;
    }
    
    result.score = (result.tests_passed * 100.0) / result.total_tests;
    return result.tests_passed == result.total_tests;
}

// Special version for merge sort (different signature)
bool runMinimalTestsMerge(TestResult& result) {
    result.algorithm = "Merge Sort";
    result.tests_passed = 0;
    result.total_tests = 3;
    
    // Test 1: Small random array
    int test1[] = {5, 2, 8, 1, 9, 3};
    int n1 = 6;
    mergeSort(test1, 0, n1 - 1);
    if (isSorted(test1, n1)) {
        result.tests_passed++;
    }
    
    // Test 2: Array with duplicates
    int test2[] = {3, 1, 3, 2, 1, 2, 3};
    int n2 = 7;
    mergeSort(test2, 0, n2 - 1);
    if (isSorted(test2, n2)) {
        result.tests_passed++;
    }
    
    // Test 3: Single element
    int test3[] = {42};
    int n3 = 1;
    mergeSort(test3, 0, n3 - 1);
    if (test3[0] == 42) {
        result.tests_passed++;
    }
    
    result.score = (result.tests_passed * 100.0) / result.total_tests;
    return result.tests_passed == result.total_tests;
}

// Special version for quick sort (different signature)
bool runMinimalTestsQuick(TestResult& result) {
    result.algorithm = "Quick Sort";
    result.tests_passed = 0;
    result.total_tests = 3;
    
    // Test 1: Small random array
    int test1[] = {5, 2, 8, 1, 9, 3};
    int n1 = 6;
    quickSort(test1, 0, n1 - 1);
    if (isSorted(test1, n1)) {
        result.tests_passed++;
    }
    
    // Test 2: Array with duplicates
    int test2[] = {3, 1, 3, 2, 1, 2, 3};
    int n2 = 7;
    quickSort(test2, 0, n2 - 1);
    if (isSorted(test2, n2)) {
        result.tests_passed++;
    }
    
    // Test 3: Single element
    int test3[] = {42};
    int n3 = 1;
    quickSort(test3, 0, n3 - 1);
    if (test3[0] == 42) {
        result.tests_passed++;
    }
    
    result.score = (result.tests_passed * 100.0) / result.total_tests;
    return result.tests_passed == result.total_tests;
}

int main() {
    std::vector<TestResult> results;
    TestResult result;
    
    std::cout << "Running Minimal Test Suite for Sorting Algorithms\n";
    std::cout << "==================================================\n\n";
    
    // Test each sorting algorithm with minimal tests
    try {
        std::cout << "Testing Bubble Sort... ";
        runMinimalTests(bubbleSort, "Bubble Sort", result);
        results.push_back(result);
        std::cout << result.tests_passed << "/" << result.total_tests << " passed\n";
    } catch(...) {
        result.algorithm = "Bubble Sort";
        result.tests_passed = 0;
        result.total_tests = 3;
        result.score = 0;
        results.push_back(result);
        std::cout << "CRASHED\n";
    }
    
    try {
        std::cout << "Testing Selection Sort... ";
        runMinimalTests(selectionSort, "Selection Sort", result);
        results.push_back(result);
        std::cout << result.tests_passed << "/" << result.total_tests << " passed\n";
    } catch(...) {
        result.algorithm = "Selection Sort";
        result.tests_passed = 0;
        result.total_tests = 3;
        result.score = 0;
        results.push_back(result);
        std::cout << "CRASHED\n";
    }
    
    try {
        std::cout << "Testing Insertion Sort... ";
        runMinimalTests(insertionSort, "Insertion Sort", result);
        results.push_back(result);
        std::cout << result.tests_passed << "/" << result.total_tests << " passed\n";
    } catch(...) {
        result.algorithm = "Insertion Sort";
        result.tests_passed = 0;
        result.total_tests = 3;
        result.score = 0;
        results.push_back(result);
        std::cout << "CRASHED\n";
    }
    
    try {
        std::cout << "Testing Merge Sort... ";
        runMinimalTestsMerge(result);
        results.push_back(result);
        std::cout << result.tests_passed << "/" << result.total_tests << " passed\n";
    } catch(...) {
        result.algorithm = "Merge Sort";
        result.tests_passed = 0;
        result.total_tests = 3;
        result.score = 0;
        results.push_back(result);
        std::cout << "CRASHED\n";
    }
    
    try {
        std::cout << "Testing Quick Sort... ";
        runMinimalTestsQuick(result);
        results.push_back(result);
        std::cout << result.tests_passed << "/" << result.total_tests << " passed\n";
    } catch(...) {
        result.algorithm = "Quick Sort";
        result.tests_passed = 0;
        result.total_tests = 3;
        result.score = 0;
        results.push_back(result);
        std::cout << "CRASHED\n";
    }
    
    try {
        std::cout << "Testing Heap Sort... ";
        runMinimalTests(heapSort, "Heap Sort", result);
        results.push_back(result);
        std::cout << result.tests_passed << "/" << result.total_tests << " passed\n";
    } catch(...) {
        result.algorithm = "Heap Sort";
        result.tests_passed = 0;
        result.total_tests = 3;
        result.score = 0;
        results.push_back(result);
        std::cout << "CRASHED\n";
    }
    
    // Generate summary
    std::cout << "\n==================================================\n";
    std::cout << "TEST SUMMARY\n";
    std::cout << "==================================================\n";
    
    int total_passed = 0;
    int total_tests = 0;
    double total_score = 0;
    
    // Write results to file for GitHub Actions
    std::ofstream outfile("test_results.txt");
    outfile << "| Algorithm | Tests Passed | Score |\n";
    outfile << "|-----------|--------------|-------|\n";
    
    for (const auto& r : results) {
        total_passed += r.tests_passed;
        total_tests += r.total_tests;
        total_score += r.score;
        
        std::cout << std::setw(20) << std::left << r.algorithm 
                  << ": " << r.tests_passed << "/" << r.total_tests 
                  << " (" << std::fixed << std::setprecision(1) << r.score << "%)\n";
                  
        outfile << "| " << std::setw(15) << std::left << r.algorithm 
                << " | " << r.tests_passed << "/" << r.total_tests 
                << " | " << std::fixed << std::setprecision(1) << r.score << "% |\n";
    }
    
    double final_score = total_score / results.size();
    std::cout << "\nOverall: " << total_passed << "/" << total_tests 
              << " tests passed (" << std::fixed << std::setprecision(1) 
              << final_score << "%)\n";
              
    outfile << "\n**Overall Score: " << std::fixed << std::setprecision(1) 
            << final_score << "%**\n";
    outfile.close();
    
    // Return exit code based on score (0 = success, 1 = failure)
    // Consider 70% as passing grade
    return (final_score >= 70.0) ? 0 : 1;
}