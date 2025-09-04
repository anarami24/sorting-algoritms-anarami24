# Sorting Algorithms Analysis

Student Name: Ana Griselda Ramírez Arámburo 
Date: 03/09/2025

## Time Complexity Analysis

### Bubble Sort
- **Best Case:** O(n) - It occurs when the array it's alredy sorted since it would only pass through it one time and it doesn't swap any elements.
- **Average Case:** O(n^2) - an element is compared many times before it's put into it's correct position.
- **Worst Case:** O(n^2) - The array is sorted in a descending order, which would lead to making the maximum swaps and comparisons.

### Selection Sort
- **Best Case:** O(n^2) - It will always search for the smallest element of the array, even if it's alredy sorted.
- **Average Case:** O(n^2) - The order of the array doesn't matter it will always do the same number of comparisons.
- **Worst Case:** O(n^2) - It will always do the same number of comparisons, the order of the array it's not a factor.

### Insertion Sort
- **Best Case:** O(n) - It happens when the array it's alredy sorted, since every new element will only get compared once.
- **Average Case:** O(n^2) - The elements of the array are out of order.
- **Worst Case:** O(n^2) - It occurs when the array is in a descending order. 

### Merge Sort
- **Best Case:** O(n log n) - Even if the array it's ordered it will always divide and conquer.
- **Average Case:** O(n log n) - It divides the array and does balanced merges (the order of the array isn't important)
- **Worst Case:** O(n log n) - Same as the other ones because this algorithm aways divides the array and half and then it merges.

### Quick Sort
- **Best Case:** O(n log n) - It happens when the pivot divides the elements in balanced halfs.
- **Average Case:** O(n log n) - The pivots tend to divide the array in an avarage matter.
- **Worst Case:** O(n^2) -When the array is alredy sorted and we choose an inconvinient pivot.

### Heap Sort
- **Best Case:** O(?) - [Explain when this occurs]
- **Average Case:** O(?) - [Explain]
- **Worst Case:** O(?) - [Explain when this occurs]

## Space Complexity Analysis

| Algorithm | Space Complexity | Explanation |
|-----------|-----------------|-------------|
| Bubble Sort | O(1) | It only needs one temporary variable for the swaps|
| Selection Sort | O(1) | It only requires one temporary variable so it can do the swaps |
| Insertion Sort | O(1) | We use the variable "inset" to do the shifts in place |
| Merge Sort | O(n) | We need temporary arrays (Left and Right) |
| Quick Sort | O(log n) | Avarage use of recurssion |
| Heap Sort | O(?) | [Explain why] |

## Empirical Performance Results

Run your implemented algorithms on different input sizes and record the execution times (in milliseconds):

### Random Data

| Algorithm | n=10 | n=100 | n=1000 | n=10000 |
|-----------|------|-------|--------|---------|
| Bubble Sort |233 microseconds | 35 microseconds | 2.444 ms| 343.586 ms |
| Selection Sort |1.000 microseconds |13.000 microseconds |1.303 ms |136.271 ms |
| Insertion Sort |1.000 microseconds |4.000 microseconds | 150.000 microseconds|9.167 ms |
| Merge Sort | 2.000 microseconds | 12.000 microseconds | 83.000 microseconds | 841.000 microseconds|
| Quick Sort | 1.000 microseconds | 6.000 microseconds | 47.000 microseconds | 761.000 microseconds |
| Heap Sort | | | | |

### Already Sorted Data

| Algorithm | n=10 | n=100 | n=1000 | n=10000 |
|-----------|------|-------|--------|---------|
| Bubble Sort | 1.000 microseconds | 12.000 microseconds| 741.000 microseconds |  67.964 ms |
| Selection Sort | | | | |
| Insertion Sort | | | | |
| Merge Sort | | | | |
| Quick Sort | | | | |
| Heap Sort | | | | |

### Reverse Sorted Data

| Algorithm | n=10 | n=100 | n=1000 | n=10000 |
|-----------|------|-------|--------|---------|
| Bubble Sort | | | | |
| Selection Sort | | | | |
| Insertion Sort | | | | |
| Merge Sort | | | | |
| Quick Sort | | | | |
| Heap Sort | | | | |

## Algorithm Comparison and Use Cases

### When to Use Each Algorithm

#### Bubble Sort
- **Best for:** [Your answer]
- **Avoid when:** [Your answer]

#### Selection Sort
- **Best for:** [Your answer]
- **Avoid when:** [Your answer]

#### Insertion Sort
- **Best for:** [Your answer]
- **Avoid when:** [Your answer]

#### Merge Sort
- **Best for:** [Your answer]
- **Avoid when:** [Your answer]

#### Quick Sort
- **Best for:** [Your answer]
- **Avoid when:** [Your answer]

#### Heap Sort
- **Best for:** [Your answer]
- **Avoid when:** [Your answer]

## Stability Analysis

Which algorithms are stable and which are not? Explain what stability means and why it matters.

[Your answer here]

## Observations and Conclusions

Based on your implementation and testing, discuss:

1. Which algorithm performed best overall? Why?
2. Which algorithm was easiest to implement? Why?
3. Were there any surprising results in your performance tests?
4. What trade-offs did you observe between time and space complexity?
5. How did the theoretical complexities compare to your empirical results?

[Your answers here]