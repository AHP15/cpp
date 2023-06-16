#include <iostream>
#include <array>

int main() {
    std::array numbers { 5, 69, 78, 14, 20 };
    using index = std::array<int, 5>::size_type;

    for(index i { 1 }; i < numbers.size(); ++i) {
        int key { numbers[i] };
        index j { i - 1 };
        while(static_cast<int>(j) >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            --j;
        };
        numbers[j + 1] = key;
    }

    for(auto num: numbers){
        std::cout << num << '\n';
    }
    return 0;
};