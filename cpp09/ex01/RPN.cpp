#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const {
    if (token.empty()) return false;
    
    if (token.length() == 1 && std::isdigit(token[0])) {
        return true;
    }
    
    return false;
}

double RPN::performOperation(double a, double b, const std::string& op) const {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        return a / b;
    }
    throw std::runtime_error("Unknown operator: " + op);
}

void RPN::processToken(const std::string& token) {
    if (isNumber(token)) {
        double num = token[0] - '0'; 
        _stack.push_back(num);
    }
    else if (isOperator(token)) {
        if (_stack.size() < 2) {
            throw std::runtime_error("Insufficient operands for operator: " + token);
        }
        
        double b = _stack.back(); _stack.pop_back();
        double a = _stack.back(); _stack.pop_back();
        
        double result = performOperation(a, b, token);
        _stack.push_back(result);
    }
    else {
        throw std::runtime_error("Invalid token: " + token);
    }
}

double RPN::evaluate(const std::string& expression) {
    _stack.clear();
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        processToken(token);
    }
    
    if (_stack.size() != 1) {
        throw std::runtime_error("Invalid expression: incorrect number of operands/operators");
    }
    
    return _stack.back();
}