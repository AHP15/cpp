#include "io.h"

#include <iostream>
#include <random>
#include <string_view>

int generate_random_number() {
    std::mt19937 mt { std::random_device{}() };
    // Create a reusable random number generator that generates uniform numbers between 1 and 100
    std::uniform_int_distribution die100{1, 100};
    return die100(mt);
}

int main() {
    using namespace std::literals;

    int random_number { generate_random_number() };
    int user_guess {};
    constexpr int max_guesses { 7 };

    while (true) {
        io::print_message(
          "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is."sv
        );
        for (int i = 1; i <= max_guesses; ++i) {
            user_guess = io::get_user_guess("Guess #"sv, i);

            if (user_guess == random_number) {
                io::print_message("Correct! You win!"sv);
                break;
            } else if (i == 7) {
                io::print_message("Sorry, you lose. The correct number was"sv);
                std::cout << random_number << '\n';
                break;
            }
            else if (user_guess < random_number) {
                io::print_message("Your guess is too low."sv);
            } else {
                io::print_message("Your guess is too high."sv);
            }
        }

        if(!io::play_again("Would you like to play again (y/n)? "sv)) {
            break;
        }
    }
    return 0;
}