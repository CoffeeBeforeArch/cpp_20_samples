// This program shows the basics of using atomic_ref in C++
// By: Nick from CoffeeBeforeArch

#include <atomic>
#include <iostream>
#include <thread>

int main() {
  // Create an integer and a atomic_ref to the integer
  int a = 0;
  std::atomic_ref<int> ref(a);

  // Our lambda for multiple threads
  auto work = [&]() {
    // Increment the non-atomic int atomically!
    for (int i = 0; i < 10000; i++) {
      ref++;
    }
  };

  // Create some threads
  std::thread t0(work);
  std::thread t1(work);
  std::thread t2(work);
  std::thread t3(work);

  // Join the threads
  t0.join();
  t1.join();
  t2.join();
  t3.join();

  // Print the value of our non-atomic int
  std::cout << "Value of a is: " << a << '\n';

  return 0;
}
