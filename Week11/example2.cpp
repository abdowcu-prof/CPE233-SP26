#include <thread>
#include <string>
#include <iostream>
#include <vector>

void processData(const std::string& name, int count, int& result) {
    result = count * 2;  // write to caller's variable
    std::cout << name << " done.\n";
}

int main() {
    int result = 0;

    // Pass by value and by ref (std::ref)
    std::thread t(processData, "Worker", 10, std::ref(result));
    t.join();

    // Lambda thread — capture by value
    std::vector<std::thread> pool;
    for (int i = 0; i < 4; ++i) {
        pool.emplace_back([i]() {  // capture i by value
            std::cout << "Task " << i << "\n";
        });
    }
    for (auto& t : pool) t.join();
}
