#include <iostream>
#include <limits>
#include <cassert>
#include <functional>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

double getNumber() {
    double input { 0.0 };
    while(true) {
        std::cout << "Enter a number: ";
        std::cin >> input;

        if (!std::cin.fail()) return input;

        std::cin.clear();
        ignoreLine();
    }
};

char getArithmatic() {
    char op {};
    do {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;

        std::cin.clear();
        ignoreLine();
    } while(op!='+' && op!='-' && op!='*' && op!='/');

    return op;
};

double add(double x, double y) {
    return x + y;
};

double subtruct(double x, double y) {
    return x - y;
};

double multiply(double x, double y) {
    return x * y;
};

double divide(double x, double y) {
    assert(y != 0 && "Can't divide by zero!");
    return x / y;
};

using ArithmeticFunction = std::function<double(double, double)>;

ArithmeticFunction getArithmeticFunction(char ope) {
    switch (ope) {
    case '+': return add;
    case '-': return subtruct;
    case '*': return multiply;
    case '/': return divide;
    default:
        assert(false && "impossible");
        return nullptr;
    }
};

int main() {
    double num1 { getNumber() };
    char ope { getArithmatic() };
    double num2 { getNumber() };

    ArithmeticFunction result { getArithmeticFunction(ope) };

    if(result)
      std::cout << result(num1, num2) << '\n';
    return 0;
}