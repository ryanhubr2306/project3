#include "stack.hpp"
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

// Function to check if a character is an operator (+, -, *, /, %)
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    std::map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2}};
    return precedence[c];
}

// Function to determine if the operator is left-associative
bool isLeftAssociative(char c) {
    // All current operators (+, -, *, /, %) are left-associative
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

// Function to convert an infix expression to a postfix expression
std::string infixToPostfix(const std::string& infix) {
    Stack<char> stack;
    std::string postfix;

    for (char c : infix) {
        if (isspace(c)) {
            continue;
        }

        if (isdigit(c) || isalpha(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.topElement() != '(') {
                postfix += stack.pop();
            }
            if (!stack.isEmpty() && stack.topElement() == '(') {
                stack.pop(); // Pop the '('
            } else {
                throw std::invalid_argument("Unmatched right parenthesis detected.");
            }
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && isLeftAssociative(c) && getPrecedence(c) <= getPrecedence(stack.topElement())) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        if (stack.topElement() == '(') {
            throw std::invalid_argument("Unmatched left parenthesis detected.");
        }
        postfix += stack.pop();
    }

    return postfix;
}
