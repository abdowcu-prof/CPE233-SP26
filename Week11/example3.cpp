#include <thread>
#include <iostream>

int counter = 0;  // shared global

void increment() {
    for (int i = 0; i < 100000; ++i)
        ++counter;  // READ-MODIFY-WRITE (3 ops!) — NOT atomic
}

int main() {
    std::thread t1(increment), t2(increment);
    t1.join();  t2.join();

    // Expected: 200000 — Actual: ??? (e.g. 143221)
    std::cout << "Counter: " << counter << "\n";
    return 0;
}

