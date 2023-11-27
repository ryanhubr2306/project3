#include "stack.hpp"
#include <iostream>
#include <string>

// Helper function to print test result
void printTestResult(bool passed, const std::string& testName) {
    std::cout << "Test " << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test for default constructor
void testDefaultConstructor() {
    Stack<int> stack;
    printTestResult(stack.isEmpty(), "Default Constructor");
}

// Test for push and pop functionality
void testPushPop() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    bool passed = stack.pop() == 2 && stack.pop() == 1;
    printTestResult(passed, "Push and Pop");
}

// Test for checking if stack is empty
void testIsEmpty() {
    Stack<int> stack;
    bool passed = stack.isEmpty();
    stack.push(1);
    passed = passed && !stack.isEmpty();
    stack.pop();
    passed = passed && stack.isEmpty();
    printTestResult(passed, "Is Empty");
}

// Add more tests for other functionalities like isFull, copy constructor, etc.

int main() {
    testDefaultConstructor();
    testPushPop();
    testIsEmpty();
    // Call other test functions here
    return 0;
}
