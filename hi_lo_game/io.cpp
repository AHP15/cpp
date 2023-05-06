#include "io.h"

#include <iostream>
#include<string_view>

namespace io {
    void print_message(std::string_view message) {
        std::cout << message << '\n';
    }

    int get_user_guess(std::string_view message, int guess_number) {
        std::cout << message << guess_number << ": ";
        int input {};
        std::cin >> input;
        return input;
    }

    bool play_again(std::string_view message) {
        std::cout << message;
        char input {};
        std::cin >> input;
        return input == 'y';
    }
}