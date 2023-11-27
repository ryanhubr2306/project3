#include "postfix_eval.hpp"
#include <iostream>
#include <vector>
#include <utility>

// Function to run a single test and print the result
bool runTest(const std::string& postfix, int expected) {
    int result = evaluatePostfix(postfix);  // Evaluate the postfix expression
    bool passed = (result == expected);  // Check if the result matches the expected value
    std::cout << "Postfix: " << postfix << " | Expected Result: " << expected << " | Actual Result: " << result;
    if (passed) {
        std::cout << " | PASSED" << std::endl;
    } else {
        std::cout << " | FAILED" << std::endl;
    }
    return passed;
}

int main() {
    // Define a vector of pairs, each containing a postfix expression and its expected result
    std::vector<std::pair<std::string, int>> tests = {
        {"2 3 +", 5},
        {"4 5 6 * + 7 -", 29},
        {"5 6 /", 0},  // Assuming integer division
        {"7 8 + 3 2 + *", 100},
        {"2 3 1 * + 9 -", -4},
        {"1 2 3 * + 4 5 + *", 60},
        {"6 2 / 3 *", 9},
        {"8 1 - 4 +", 11},
        {"7", 7}
    };

    bool allTestsPassed = true;
    
    // Iterate through the test cases and run each one
    for (const auto& test : tests) {
        if (!runTest(test.first, test.second)) {
            allTestsPassed = false;
        }
    }

    // Print whether all tests passed or if some tests failed
    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}
