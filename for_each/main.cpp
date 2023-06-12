#include <string_view>
#include <string>
#include <iostream>

int main() {
  constexpr std::string_view names[] { 
    "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" 
  };

  std::cout << "Enter a name: ";
  std::string input {};
  std::cin >> input;
  bool nameFound { false };

  for(std::string_view name: names) {
    if (name == input) {
      std::cout << name << " was found\n";
      nameFound = true;
      break;
    }
  }

  if (!nameFound) {
    std::cout << input << " was not found\n";
  }
  return 0;
}