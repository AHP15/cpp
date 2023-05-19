#include <string_view>
#include <iostream>

enum class Animals {
    pig, chicken, goat, cat, dog, duck,
};

std::string_view getAnimalName(Animals animal) {
    using namespace std::literals; 
    using enum Animals;
    switch(animal) {
    case pig:     return "pig"sv;
    case chicken: return "chicken"sv;
    case goat:    return "chicken"sv;
    case cat:     return "cat"sv;
    case dog:     return "dog"sv;
    case duck:    return "duck"sv;
    default:      return "Unknown animal!"sv;
    }
}

void printNumberOfLegs(Animals animal) {
    using enum Animals;
    switch (animal) {
    case pig:
        std::cout << "A pig has 4 legs\n";
        break;
    case chicken:
        std::cout << "A chicken has 2 legs\n";
        break;
    case goat:
        std::cout << "A goat has 4 legs\n";
        break;
    case cat:
        std::cout << "A cat has 4 legs\n";
        break;
    case dog:
        std::cout << "A dog has 4 legs\n";
        break;
    case duck:
        std::cout << "A duck has 2 legs\n";
        break;
    default:
        std::cout << "Unknown animal!\n";
    }
}

int main() {
    printNumberOfLegs(Animals::cat);
    printNumberOfLegs(Animals::chicken);
    return 0;
}