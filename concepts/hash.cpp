// This program shows off custom concepts in C++
// By: Nick From CoffeeBeforeArch

#include <concepts>
#include <cstddef>
#include <iostream>
#include <string>

// For our string literal
using namespace std::literals;

// Here's an example of a custom concept from cppreference.com
// For a given type T, we define a concept called Hashable
template <typename T>
concept Hashable = requires(T a) {
  // Hashable requires the expression of hashing type T
  // to be convertable to size_t
  { std::hash<T>{}(a) }
  ->std::convertible_to<std::size_t>;
};

// Here's a function where we use the concept
template <typename  T>
void func(T a) {
  std::cout << "Hash of type = " << std::hash<T>{}(a) << '\n';
};

// Here's an empty struct
// There's no data members, so the size is 0 (nothing to hash!)
struct empty_struct {};

int main() {
  // We can hash a string...
  func("abc"s);
  // But we can't hash our empty_struct!
  func(empty_struct{});

  return 0;
}
