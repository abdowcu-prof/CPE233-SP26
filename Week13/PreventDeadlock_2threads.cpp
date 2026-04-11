// Preventing Deadlock

/* 

Always lock the mutexes in the same order in every thread.

For example:

first lock m1
then lock m2

And never let another thread do:

first lock m2
then lock m1

That opposite order can cause deadlock.

*/ 



#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int x = 0;
int y = 0;

mutex m1;
mutex m2;

// Thread 1
void task1() {
        while (1)
        {
                m1.lock();
                cout << "Task 1 locked m1" << endl;
            
                this_thread::sleep_for(chrono::milliseconds(100));
            
                m2.lock();
                cout << "Task 1 locked m2" << endl;
            
                x = x + 1;
                y = y + 1;
            
                cout << "Task 1 finished work" << endl;
            
                m2.unlock();
                m1.unlock();
                
        }
}

// Thread 2
void task2() {
    
    while (1) {
            m1.lock();
            cout << "Task 2 locked m1" << endl;
        
            this_thread::sleep_for(chrono::milliseconds(100));
        
            m2.lock();
            cout << "Task 2 locked m2" << endl;
        
            x = x + 10;
            y = y + 10;
        
            cout << "Task 2 finished work" << endl;
        
            m2.unlock();
            m1.unlock();
        
    }
  
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}