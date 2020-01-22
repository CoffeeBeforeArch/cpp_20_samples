// This program shows off the basics of consteval in C++20
// By: Nick from CoffeeBeforeArch

#include <cstdlib>
#include <iostream>

// A consteval function
// This MUST be evaluated at compile time
consteval int fibonacci(int N) {
  if (N <= 1) return N;
  return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
  // This works with our consteval function
  int val = fibonacci(22);

  // This does not!
  // val = fibonacci(rand() % 20);

  // Print the result
  std::cout << "The fibonacci number is: " << val << '\n';

  return 0;
}
