#include <iostream>
#include <cstdlib>
using namespace std;

int g1 = 77;
int g2;

int show(int x) {
    int local1 = 5;
    static int local2;
    static int local3 = 55; 
    int local4; 
    int local5 = x; 
    
    local2 = local2 + 1; 
    local3 = local3 + 1; 
    // local4 not initialized so the memory has garbage
    local4 = local4 + x; 
    
    // Updated output for local variables
    cout << "local1 value: " << local1 << ",\tlocal1 address: " << &local1 << endl;
    cout << "local2 value: " << local2 << ",\tlocal2 address: " << &local2 << endl;
    cout << "local3 value: " << local3 << ",\tlocal3 address: " << &local3 << endl;
    cout << "local4 value: " << local4 << ",\tlocal4 address: " << &local4 << endl; 
    cout << "local5 value: " << local5 << ",\tlocal5 address: " << &local5 << endl; 
    
    return (x * 10); 
}

int main() {
    int* heapVar = new int;
    int myReturnValue; 
    
    g2 = g1 + 100; 
 
    // Updated output for global variables
    cout << "g1 value: " << g1 << ",\tg1 address: " << &g1 << endl;
    cout << "g2 value: " << g2 << ",\tg2 address: " << &g2 << endl;

    cout << "Enter a value for the dynamically allocated Integer: " << endl;
    cin >> *heapVar;

    // Updated output for heap variable
    cout << "heapVar value: " << *heapVar << ",\theapVar address: " << heapVar << endl; 

    myReturnValue = show(*heapVar);

    // Updated output for return value
    cout << "myReturnValue value: " << myReturnValue << ",\tmyReturnValue address: " << &myReturnValue << endl;
    
    delete heapVar;
    return 0;
}
