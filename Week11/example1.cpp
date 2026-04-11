#include <iostream>
#include <thread>

void greet(int id) {
    std::cout << "Hello from thread " << id << "\n";
}

int main() {
    // Construct thread — starts IMMEDIATELY
    std::thread t1(greet, 1);
    std::thread t2(greet, 2);

    // join() — wait for the thread to finish
    t1.join();
    t2.join();

    // detach() — fire-and-forget (NOT joined)
    // std::thread t3(greet, 3);  t3.detach();

    return 0;
}
