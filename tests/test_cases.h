#ifndef TEST_CASES_H
#define TEST_CASES_H

#include <vector>
#include <string>
#include <functional>

struct TestCase {
    std::string name;
    std::vector<int> input;
    std::vector<int> expected;
    std::string description;
};

class TestSuite {
public:
    static std::vector<TestCase> getBasicTestCases() {
        return {
            {
                "Empty Array",
                {},
                {},
                "Should handle empty array without errors"
            },
            {
                "Single Element",
                {42},
                {42},
                "Should handle single element array"
            },
            {
                "Two Elements - Sorted",
                {1, 2},
                {1, 2},
                "Should handle already sorted two-element array"
            },
            {
                "Two Elements - Unsorted",
                {2, 1},
                {1, 2},
                "Should sort two-element array"
            },
            {
                "Already Sorted",
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                "Should handle already sorted array efficiently"
            },
            {
                "Reverse Sorted",
                {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                "Should sort reverse ordered array"
            },
            {
                "Random Order",
                {3, 7, 1, 4, 6, 2, 5, 8, 10, 9},
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                "Should sort randomly ordered array"
            },
            {
                "Duplicates",
                {5, 2, 8, 2, 9, 1, 5, 5, 1, 9},
                {1, 1, 2, 2, 5, 5, 5, 8, 9, 9},
                "Should handle arrays with duplicate values"
            },
            {
                "All Same",
                {7, 7, 7, 7, 7},
                {7, 7, 7, 7, 7},
                "Should handle array with all identical elements"
            },
            {
                "Negative Numbers",
                {-5, 3, -2, 0, -8, 7, 1, -3},
                {-8, -5, -3, -2, 0, 1, 3, 7},
                "Should handle negative numbers correctly"
            },
            {
                "Large Range",
                {1000, -1000, 0, 500, -500, 250, -250, 750, -750},
                {-1000, -750, -500, -250, 0, 250, 500, 750, 1000},
                "Should handle large value ranges"
            },
            {
                "Nearly Sorted",
                {1, 2, 4, 3, 5, 6, 8, 7, 9, 10},
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                "Should efficiently sort nearly sorted array"
            }
        };
    }
    
    static std::vector<TestCase> getStressTestCases() {
        std::vector<TestCase> stressTests;
        
        std::vector<int> large100(100);
        std::vector<int> large100Sorted(100);
        for (int i = 0; i < 100; i++) {
            large100[i] = 100 - i;
            large100Sorted[i] = i + 1;
        }
        stressTests.push_back({
            "Large Array (100 elements)",
            large100,
            large100Sorted,
            "Should handle larger arrays"
        });
        
        std::vector<int> large1000(1000);
        std::vector<int> large1000Sorted(1000);
        for (int i = 0; i < 1000; i++) {
            large1000[i] = (i * 37 + 17) % 1000;
            large1000Sorted[i] = i;
        }
        std::sort(large1000Sorted.begin(), large1000Sorted.end());
        stressTests.push_back({
            "Very Large Array (1000 elements)",
            large1000,
            large1000Sorted,
            "Should handle very large arrays"
        });
        
        return stressTests;
    }
    
    static bool arraysEqual(const int arr1[], const int arr2[], int n) {
        for (int i = 0; i < n; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
    
    static void printTestResult(const std::string& testName, bool passed) {
        const std::string RESET = "\033[0m";
        const std::string GREEN = "\033[32m";
        const std::string RED = "\033[31m";
        
        if (passed) {
            std::cout << GREEN << "[PASS]" << RESET;
        } else {
            std::cout << RED << "[FAIL]" << RESET;
        }
        std::cout << " " << testName << std::endl;
    }
    
    static void printTestSummary(int passed, int total) {
        const std::string RESET = "\033[0m";
        const std::string GREEN = "\033[32m";
        const std::string YELLOW = "\033[33m";
        const std::string RED = "\033[31m";
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "Test Results: ";
        
        if (passed == total) {
            std::cout << GREEN << "ALL TESTS PASSED!" << RESET << std::endl;
        } else if (passed > total / 2) {
            std::cout << YELLOW << "PARTIAL SUCCESS" << RESET << std::endl;
        } else {
            std::cout << RED << "TESTS FAILED" << RESET << std::endl;
        }
        
        std::cout << "Passed: " << passed << "/" << total << std::endl;
        std::cout << "========================================" << std::endl;
    }
};

#endif