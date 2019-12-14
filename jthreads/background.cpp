// This program shows off the basics of jthreads in C++
// By: Nick from CoffeeBeforeArch

#include <iostream>
#include <thread>

int main() {
  // What happens when we spawn a thread, and we don't join it?
  // If it's join-able, std::terminate gets called (usually calls abort)
  std::thread t0([]() { std::cout << "Printing from the new thread!\n"; });

  // If we call join, we wait for the thread to finish
  // t0.join();

  // If we call detach, the thread is no longer join-able (terminate isn't
  // called)
  // However, if main exits, our string may not print!
  t0.detach();
  
  return 0;
}
