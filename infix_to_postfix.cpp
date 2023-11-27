#include "infix_to_postfix.hpp"
#include "stack.hpp"
#include <cctype>
#include <stdexcept>
#include <map>

// Helper function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Function to convert infix to postfix
std::string infixToPostfix(const std::string& infix) {
    Stack<char> stack;
    std::string postfix;

    // Define a map to store operator precedence
    std::map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}, {'(', 0}};

    for (char c : infix) {
        if (isspace(c)) {
            continue; // Skip spaces
        }

        if (isdigit(c) || isalpha(c)) {
            postfix += c; // Append operand to postfix
        } else if (c == '(') {
            stack.push(c); // Push '(' to stack
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.topElement() != '(') {
                postfix += stack.pop(); // Append operators to postfix
            }
            if (!stack.isEmpty()) {
                stack.pop(); // Pop '(' from the stack
            }
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence[c] <= precedence[stack.topElement()] && stack.topElement() != '(') {
                postfix += stack.pop(); // Append top of stack
            }
            stack.push(c); // Push current operator to stack
        }
    }

    while (!stack.isEmpty()) {
        if (stack.topElement() == '(') {
            throw std::invalid_argument("Unmatched parenthesis detected.");
        }
        postfix += stack.pop(); // Append remaining operators to postfix
    }

    return postfix;
}
