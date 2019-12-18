// This program shows off the basics of using the spaceship operator in C++20
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <vector>

// A simple struct with 2 integers
// How do we compare two of these structs?
struct Ints {
  int a;
  int b;

  // The spaceship operator allows us avoid a bunch of boilerplate code!
  auto operator<=>(const Ints&) const = default;

  // Having to implement all operations like this would be a hassle!
  /*
  bool operator<(const Ints &i) {
    // Compare a's, then b's
    if (a < i.a || (a == i.a && b < i.b)) {
      return true;
    } else {
      return false;
    }
  }
  */
};

int main() {
  // We'll create a couple of our structs
  Ints t1 = {1, 2};
  Ints t2 = {3, 4};

  // Put them in a vector
  std::vector<Ints> v;
  v.push_back(t1);
  v.push_back(t2);

  // And sort them!
  // std::sort() requires the '<' operator!
  std::sort(begin(v), end(v));
  
  return 0;
}
