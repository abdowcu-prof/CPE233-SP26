#include <iostream>
using namespace std;

// Three functions with the SAME signature
int add(int a, int b)      { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    // Declare a function pointer matching the signature
    int (*operation)(int, int);

    operation = add;         // point to add()
    cout << operation(10, 4) << endl;  // prints 14

    operation = subtract;    // point to subtract()
    cout << operation(10, 4) << endl;  // prints 6

    operation = multiply;    // point to multiply()
    cout << operation(10, 4) << endl;  // prints 40
    return 0;
}
