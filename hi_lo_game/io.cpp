#include "io.h"

#include <iostream>
#include<string_view>
#include <limits>

namespace io {
    void print_message(std::string_view message) {
        std::cout << message << '\n';
    }

    int get_user_guess(std::string_view message, int guess_number) {
        while(true) {
            std::cout << message << guess_number << ": ";
            int input {};
            std::cin >> input;

            if (std::cin.fail()) {
                std::cin.clear(); // put us back in 'normal' operation mode
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (input < 1 || input > 100) {
                std::cin.clear();
                continue;
            }
        
            return input;
        }
    }

    bool play_again(std::string_view message) {
        while(true) {
            std::cout << message;
            char input {};
            std::cin >> input;

            switch (input) {
            case 'y':
               return true;
            case 'n':
               return false;
            default:
                std::cin.clear(); // put us back in 'normal' operation mode
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}