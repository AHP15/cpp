#include <iostream>
#include <utility>
#include <iterator> 

void bubbleSort(int arr[], int length) {
  for (int i { 0 }; i < length - 1; ++i) {
    bool swapping { false };
    for(int j { 0 }; j < length - (i + 1); ++j) {
      if (arr[j] > arr[j  + 1]) {
        std::swap(arr[j + 1] , arr[j]);
        swapping = true;
      }
    }
    if (!swapping) return;
  }
};

int main() {
  int array[] { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
  int length { static_cast<int>(std::size(array)) };
  bubbleSort(array, length);
  
  for (int i { 0 }; i < length; ++i) {
    std::cout << array[i] << '\n';
  }
  return 0;
}