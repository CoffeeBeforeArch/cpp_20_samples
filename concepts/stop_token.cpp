// This program shows off the basics of stop tokens in C++20
// By: Nick from CoffeeBeforeArch

#include <chrono>
#include <concepts>
#include <iostream>
#include <thread>

using namespace std::chrono;

// Here, we constrain the type to those that are signed and integral
// This helps avoid long, and non-intuitive template error messages
// Instead, we get a simple one that says the constraint that failed!
template <std::signed_integral T>
void sleepFunc(T num) {
  std::this_thread::sleep_for(seconds(num));
}

int main() {
  // Let's create a jthread an pass it a stop token
  std::jthread jt0([](std::stop_token tk) {
    // Print in a loop
    for (int i = 0; i < 10; i++) {
      std::cout << "Printing value: " << i << '\n';

      // Stop, if that has been requested
      if (tk.stop_requested()) {
        return;
      }

      // Sleep so this doesn't finish too quickly
      // This should be a long int, not a double!
      sleepFunc(1.5);
    }
  });

  // Pause the main thread before cancelling the jthread
  sleepFunc(5);

  // Request for our jthread to stop
  jt0.request_stop();
  std::cout << "Stopped the jthread!\n";

  return 0;
}
