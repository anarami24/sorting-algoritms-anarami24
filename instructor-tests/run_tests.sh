#!/bin/bash

# run_tests.sh - Minimal test runner for GitHub Classroom
# Usage: ./run_tests.sh <path-to-student-code>

STUDENT_DIR=$1
TEST_DIR=$(dirname "$0")

if [ -z "$STUDENT_DIR" ]; then
    echo "Error: Please provide path to student code"
    echo "Usage: ./run_tests.sh <path-to-student-code>"
    exit 1
fi

echo "================================"
echo "GitHub Classroom Autograder"
echo "Sorting Algorithms Test Suite"
echo "================================"
echo ""

# Check if student directory exists
if [ ! -d "$STUDENT_DIR" ]; then
    echo "Error: Student code directory not found: $STUDENT_DIR"
    exit 1
fi

# Check for required student files
if [ ! -f "$STUDENT_DIR/src/sorting.cpp" ]; then
    echo "Error: sorting.cpp not found in $STUDENT_DIR/src/"
    echo "Score: 0/100"
    echo "| Algorithm | Tests Passed | Score |" > test_results.txt
    echo "|-----------|--------------|-------|" >> test_results.txt
    echo "| All | 0/18 | 0% |" >> test_results.txt
    echo "" >> test_results.txt
    echo "**Overall Score: 0%**" >> test_results.txt
    exit 1
fi

if [ ! -f "$STUDENT_DIR/src/sorting.h" ]; then
    echo "Error: sorting.h not found in $STUDENT_DIR/src/"
    echo "Score: 0/100"
    echo "| Algorithm | Tests Passed | Score |" > test_results.txt
    echo "|-----------|--------------|-------|" >> test_results.txt
    echo "| All | 0/18 | 0% |" >> test_results.txt
    echo "" >> test_results.txt
    echo "**Overall Score: 0%**" >> test_results.txt
    exit 1
fi

# Compile test suite with student code
echo "Compiling test suite..."
g++ -std=c++11 -o test_runner \
    "$TEST_DIR/minimal_tests.cpp" \
    "$STUDENT_DIR/src/sorting.cpp" \
    -I"$STUDENT_DIR/src" \
    -O2 -Wall 2>/dev/null

if [ $? -ne 0 ]; then
    echo "Compilation failed. Attempting with less strict flags..."
    g++ -std=c++11 -o test_runner \
        "$TEST_DIR/minimal_tests.cpp" \
        "$STUDENT_DIR/src/sorting.cpp" \
        -I"$STUDENT_DIR/src" \
        -O0 2>/dev/null
    
    if [ $? -ne 0 ]; then
        echo "Error: Compilation failed"
        echo "Score: 0/100"
        echo "| Algorithm | Tests Passed | Score |" > test_results.txt
        echo "|-----------|--------------|-------|" >> test_results.txt
        echo "| Compilation Error | 0/18 | 0% |" >> test_results.txt
        echo "" >> test_results.txt
        echo "**Overall Score: 0%**" >> test_results.txt
        exit 1
    fi
fi

echo "Compilation successful!"
echo ""

# Run tests with timeout (10 seconds max to prevent infinite loops)
echo "Running tests (timeout: 10s)..."
echo ""
timeout 10s ./test_runner

TEST_EXIT_CODE=$?

if [ $TEST_EXIT_CODE -eq 124 ]; then
    echo ""
    echo "Error: Tests timed out (possible infinite loop)"
    echo "Score: 0/100"
    echo "| Algorithm | Tests Passed | Score |" > test_results.txt
    echo "|-----------|--------------|-------|" >> test_results.txt
    echo "| Timeout | 0/18 | 0% |" >> test_results.txt
    echo "" >> test_results.txt
    echo "**Overall Score: 0%**" >> test_results.txt
    exit 1
fi

# Check if test_results.txt was created
if [ ! -f "test_results.txt" ]; then
    echo "Error: Test results file not generated"
    echo "Score: 0/100"
    exit 1
fi

# Display final score
echo ""
echo "================================"
echo "Test execution completed!"
echo "================================"

# Clean up
rm -f test_runner

# Exit with test exit code (0 = pass, 1 = fail)
exit $TEST_EXIT_CODE