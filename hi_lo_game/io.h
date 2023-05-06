#ifndef IO_H
#define IO_H

#include<string_view>
namespace io {
    void print_message(std::string_view message);
    int get_user_guess(std::string_view message, int guess_number);
    bool play_again(std::string_view message);
}
#endif