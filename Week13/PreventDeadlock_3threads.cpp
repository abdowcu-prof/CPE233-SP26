#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex r1;
mutex r2;
mutex r3;

int value1 = 0;
int value2 = 0;
int value3 = 0;

// Thread 1 uses r1 then r2
void task1() {
    
    
            for (int i = 0; i < 1000; i++) {

                    r1.lock();
                    cout << "Task 1 locked r1" << endl;
                
                    this_thread::sleep_for(chrono::milliseconds(100));
                
                    r2.lock();
                    cout << "Task 1 locked r2" << endl;
                
                    value1 = value1 + 1;
                    value2 = value2 + 1;
                
                    cout << "Task 1 finished work" << endl;
                
                    r2.unlock();
                    r1.unlock();
            }        
}

// Thread 2 uses r2 then r3
void task2() {

    for (int i = 0; i < 1000; i++) {
        
                r2.lock();
                cout << "Task 2 locked r2" << endl;
            
                this_thread::sleep_for(chrono::milliseconds(100));
            
                r3.lock();
                cout << "Task 2 locked r3" << endl;
            
                value2 = value2 + 5;
                value3 = value3 + 5;
            
                cout << "Task 2 finished work" << endl;
            
                r3.unlock();
                r2.unlock();
    }
        
        
}

// Thread 3 uses r1 then r3
void task3() {
    
    for (int i = 0; i < 1000; i++) {
            
               r1.lock();
            cout << "Task 3 locked r1" << endl;
        
            this_thread::sleep_for(chrono::milliseconds(100));
        
            r3.lock();
            cout << "Task 3 locked r3" << endl;
        
            value1 = value1 + 9;
            value3 = value3 + 9;
        
            cout << "Task 3 finished work" << endl;
        
            r3.unlock();
            r1.unlock();
    }
 
}

int main() {
    thread t1(task1);
    thread t2(task2);
    thread t3(task3);

    t1.join();
    t2.join();
    t3.join();

    cout << "Final values:" << endl;
    cout << "value1 = " << value1 << endl;
    cout << "value2 = " << value2 << endl;
    cout << "value3 = " << value3 << endl;

    return 0;
}