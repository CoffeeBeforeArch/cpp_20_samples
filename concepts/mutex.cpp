// This program shows off a custom concept in C++20
// By: Nick from CoffeeBeforeArch

#include <concepts>
#include <mutex>
#include <string>

// For our string literal
using namespace std::literals;

// A simplified concept for checking equality
template <typename T>
concept EqualityComparable = requires(T a, T b) {
  // We can check if the result of the expression is convertible to a bool
  //{ a == b }
  //->std::convertible_to<bool>;
  // We can also use another concept!
  a == b; requires std::boolean<decltype(a == b)>;
};

// Here's are function we use the concept with
// We can use our concept, or the standard one
template <EqualityComparable T>
// template <std::equality_comparable T>
void f(T&& t1) {
  if (t1 == t1) {
    // Empty function body
  }
}

int main() {
  // Call our function with a string
  f("abc"s);
  // Call our function with a mutex (fails!)
  std::mutex mtx;
  f(mtx);

  return 0;
}
