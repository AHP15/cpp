#include <iostream>

namespace constants {
    inline constexpr double pi { 3.14159 };
}

using Degrees = double;
using Radians = double;

Radians convertToRadians(Degrees degrees) {
    return degrees * constants::pi / 180;
}

template <typename T>
T add(T x, T y) {
    return x + y;
}

template <typename U>
U mult(U x, int y) {
    return x * y;
}

template <typename T, typename U>
auto sub(T x, U y) {
    return x - y;
}

int main() {
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

    std::cout << mult(6, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

    return 0;
}
