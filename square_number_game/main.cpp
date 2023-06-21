#include <vector>
#include <iostream>
#include <string_view>
#include <random>
#include <ctime>
#include <algorithm>
#include <cmath>

using Numbers = std::vector<int>;

namespace config {
    constexpr int multiplierMin{ 2 };
    constexpr int multiplierMax{ 4 };
    constexpr int maximumWrongAnswer{ 4 };
};

int getIntegerFromUser(std::string_view message) {
    int input {};
    std::cout << message;
    std::cin >> input;
    return input;
};

int getRandomInt(int min, int max) {
    std::mt19937 mt { static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    return std::uniform_int_distribution{ min, max }(mt);
};

Numbers generateNumbers(int start, int length, int multiplier) {
    Numbers numbers(static_cast<Numbers::size_type>(length));
    int i { start };
    for(auto& number: numbers) {
        number = i * i * multiplier;
        ++i;
    }

    return numbers;
};

Numbers generateUserNumbers(int multiplier) {
    int start { getIntegerFromUser("Start where? ") };
    int length { getIntegerFromUser("How many? ") };
    return generateNumbers(start, length, multiplier);
};

bool findAndRemove(Numbers& numbers, int guess) {
    auto found { std::find(numbers.begin(), numbers.end(), guess) };
    if(found == numbers.end()) return false;
    numbers.erase(found);
    return true;
};

int findClosestNumber(const Numbers& numbers, int guess) {
    auto closest { std::min_element(numbers.begin(), numbers.end(), [=](int a, int b){
        return (std::abs(a - guess) < std::abs(b - guess));
    })};
    return *closest;
};

void printTask(Numbers::size_type count, int multiplier) {
    std::cout << "I generated " << count
              << " square numbers. Do you know what each number is after multiplying it by "
              << multiplier << "?\n";
}

// Called when the user guesses a number correctly.
void printSuccess(Numbers::size_type numbersLeft) {
    std::cout << "Nice! ";

    if (numbersLeft == 0){
        std::cout << "You found all numbers, good job!\n";
    }
    else {
        std::cout << numbersLeft << " number(s) left.\n";
    }
};

// Called when the user guesses a number that is not in the numbers.
void printFailure(const Numbers& numbers, int guess) {
    int closest{ findClosestNumber(numbers, guess) };

    std::cout << guess << " is wrong!";

    if (std::abs(closest - guess) <= config::maximumWrongAnswer){
        std::cout << " Try " << closest << " next time.\n";
    }
    else {
        std::cout << '\n';
    }
};

// Returns false if the game is over. True otherwise.
bool playRound(Numbers& numbers) {
    int guess{ getIntegerFromUser(">") };

    if (findAndRemove(numbers, guess)) {
        printSuccess(numbers.size());

        return !numbers.empty();
    }
    printFailure(numbers, guess);
    return false;
}

int main() {
    int multiplier{ getRandomInt(config::multiplierMin, config::multiplierMax) };
    Numbers numbers{ generateUserNumbers(multiplier) };

    printTask(numbers.size(), multiplier);

    while (playRound(numbers))
        ;
    return 0;
};