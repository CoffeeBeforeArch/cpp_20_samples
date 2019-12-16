// This program shows off the basics of spans in C++20
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <span>

// An old-fashioned way of passing an array to a function
// Easy to make mistakes, requires us to pass a value
void printArray(const int a[], const int N) {
  for (int i = 0; i < N; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

// A modern way using spans!
// It replaces pointer-length pairs with a view of contiguous storage
// Allows us to use range-based for loop, find_if, etc, without any extra
// overhead from a container
void printSpan(std::span<int> s) {
  for (auto i : s) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main() {
  // Create a new array and initialize it to 0
  int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Call a function using our array and its length
  printArray(a, 10);

  // Call the function that uses a span
  printSpan(a);

  return 0;
}
