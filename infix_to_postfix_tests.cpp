#include "infix_to_postfix.hpp"
#include <iostream>
#include <vector>
#include <utility>

bool runTest(const std::string& infix, const std::string& expected) {
    std::string postfix = infixToPostfix(infix);
    return postfix == expected;
}

int main() {
   std::vector<std::pair<std::string, std::string>> tests = {
    {"a+b", "ab+"},
    {"a+b*c", "abc*+"},
    {"(a+b)*c", "ab+c*"},
    {"a+(b*c)", "abc*+"},
    {"a*b+c", "ab*c+"},
    {"a+b-c", "abc-+"},
    {"a*(b+c)", "abc+*"},
    {"a/b", "ab/"},
    {"a+b-c*d/e", "abcd*+e/-"}
    };

    bool allTestsPassed = true;
    for (const auto& test : tests) {
        if (!runTest(test.first, test.second)) {
            allTestsPassed = false;
            std::cout << "Test failed for Infix: " << test.first << " | Expected Postfix: " << test.second << std::endl;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}
