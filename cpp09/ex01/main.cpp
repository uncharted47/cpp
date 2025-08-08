#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        RPN calculator;
        double result = calculator.evaluate(argv[1]);
        std::cout << static_cast<int>(result) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}