# Makefile for Sorting Algorithms Project

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
DEBUG_FLAGS = -g -DDEBUG

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Source files
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/sorting.cpp
TEST_SOURCES = $(TEST_DIR)/test_runner.cpp $(SRC_DIR)/sorting.cpp

# Object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
TEST_OBJECTS = $(BUILD_DIR)/test_runner.o $(BUILD_DIR)/sorting.o

# Executable names
MAIN_EXEC = sorting_demo
TEST_EXEC = test_runner

# Default target
all: $(BUILD_DIR) $(MAIN_EXEC)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build main executable
$(MAIN_EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build complete! Run with ./$(MAIN_EXEC)"

# Build test executable
test: $(BUILD_DIR) $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/test_runner.o: $(TEST_DIR)/test_runner.cpp
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) -c -o $@ $<

# Debug build
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: clean all

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(MAIN_EXEC) $(TEST_EXEC)
	@echo "Clean complete!"

# Run the main program
run: all
	./$(MAIN_EXEC)

# Memory check with valgrind (if available)
memcheck: debug
	valgrind --leak-check=full --show-leak-kinds=all ./$(MAIN_EXEC)

# Help target
help:
	@echo "Available targets:"
	@echo "  make all      - Build the main program (default)"
	@echo "  make test     - Build and run tests"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make run      - Build and run the main program"
	@echo "  make clean    - Remove all build files"
	@echo "  make memcheck - Run with valgrind (requires valgrind)"
	@echo "  make help     - Show this help message"

.PHONY: all test debug clean run memcheck help