#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <vector>

class RPN {
private:
    std::vector<double> _stack;
    
    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    double performOperation(double a, double b, const std::string& op) const;
    void processToken(const std::string& token);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    double evaluate(const std::string& expression);
};

#endif