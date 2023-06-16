#include <array>
#include <numeric>
#include <iostream>

enum Items {
  health_potions,
  torches,
  arrows,
  max_items
};

using Inventory = std::array<int, max_items>;
int countTotalItems(const Inventory& arr) {
  return std::reduce(arr.begin(), arr.end());
};

int main() {
  Inventory items { 2, 5, 10 };
  std::cout << "Total items: " << countTotalItems(items)
            << '\n'
            << "Total torches: " << items[torches]
            << '\n';
  return 0;
}