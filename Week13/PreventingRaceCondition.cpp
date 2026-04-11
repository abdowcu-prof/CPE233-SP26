// Preventing Race Condition 

/* 

1) lock 

2) Critical code

3) Unlock (immediately after you are done)

*/ 




#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

const int SIZE = 100;

int buffer[SIZE];

int itemCount = 0;

mutex m;

void producer() {
    for (int item = 1; item <= 1000; item++) {

        bool inserted = false;

        while (inserted == false) {

            m.lock();

            if (itemCount < SIZE) {
                buffer[itemCount] = item;
                cout << "Producer added: " << item << endl;
                itemCount = itemCount + 1;
                inserted = true;
            }

            m.unlock();

            this_thread::sleep_for(chrono::milliseconds(200));
        }
    }
}

void consumer() {
    for (int i = 1; i <= 1000; i++) {

        bool removed = false;

        while (removed == false) {

            m.lock();

            if (itemCount > 0) {
                int item = buffer[0];

                for (int j = 0; j < itemCount - 1; j++) {
                    buffer[j] = buffer[j + 1];
                }

                itemCount = itemCount - 1;

                cout << "Consumer removed: " << item << endl;
                removed = true;
            }

            m.unlock();

            this_thread::sleep_for(chrono::milliseconds(300));
        }
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    cout << "Done" << endl;
    return 0;
}