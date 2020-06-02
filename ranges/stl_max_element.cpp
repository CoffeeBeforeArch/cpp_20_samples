// This program shows off STL max element in C++
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
  // Number of elements to sort
  const unsigned N = 20;

  // Our vector to sort
  std::vector<int> v(N);

  // Set up our random number generator
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 255);

  // Generate our random inputs
  std::ranges::generate(v, [&]() { return dist(rng); });

  // Print the vector
  std::cout << "Elements in v: ";
  for (auto e : v) std::cout << e << " ";
  std::cout << '\n';

  // Find the max element
  std::cout << "Max Element = " << *(std::ranges::max_element(v)) << '\n';

  return 0;
}
