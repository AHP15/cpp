#include <iostream>
#include <cassert>

int factorial(int n) {
    assert(n > 0 && "n must be strictly positive!");
    if(n == 1) return 1;
    return factorial(n - 1) * n;
};

int digitSum(int n) {
    assert(n >= 0 && "n must be positive!");
    if(n == 0) return 0;
    return digitSum(n / 10) + (n % 10);
};

int main() {
    std::cout << factorial(7) << '\n';
    std::cout << digitSum(93427) << '\n';
    return 0;
}