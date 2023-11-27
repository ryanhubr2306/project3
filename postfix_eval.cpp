#include "stack.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluateOperation(int operand1, int operand2, char operation) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                throw std::runtime_error("Division by zero error");
            }
            return operand1 / operand2;
        default: 
            throw std::invalid_argument(std::string("Invalid operator: ") + operation);
    }
}

int evaluatePostfix(const std::string& postfix) {
    if (postfix.empty()) {
        throw std::invalid_argument("Empty expression cannot be evaluated");
    }

    Stack<int> stack; // Use the correct member variable name "size" here

    std::istringstream iss(postfix);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            stack.push(std::stoi(token));
        } else if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size < 2) { // Use the correct member variable name "size" here
                throw std::runtime_error("Insufficient operands for operation: " + token);
            }
            int operand2 = stack.pop();

            int operand1 = stack.pop();

            int result = evaluateOperation(operand1, operand2, token[0]);
            stack.push(result);
        } else {
            throw std::invalid_argument("Invalid token in expression: " + token);
        }
    }

    if (stack.size != 1) { // Use the correct member variable name "size" here
        throw std::runtime_error("Invalid expression: leftover operands or operators");
    }

    return stack.topElement();
}
