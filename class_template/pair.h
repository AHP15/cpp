#ifndef PAIR_H
#define PAIR_H
#include <iostream>
template <typename T, typename U>
struct Pair {
  T first;
  U second;
};

template <typename T, typename U>
void print(Pair<T, U> p) {
  std::cout << '[' << p.first << ", " << p.second << ']' << '\n';
};

#endif