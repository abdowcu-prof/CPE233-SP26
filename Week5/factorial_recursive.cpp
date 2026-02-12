#include <iostream>
#include <stdexcept>
using namespace std;


unsigned long long factorial(unsigned int n) {

    // Base case: 0! = 1
    if (n == 0)
        return 1;

    // Recursive case
    return n * factorial(n - 1);
}

int main() {

    int input;

    cout << "Enter a non-negative integer (0–20 recommended): ";
    cin >> input;

    if (input < 0) {
        cout << "Error: Factorial is undefined for negative numbers." << endl;
        return 1;
    }

    if (input > 20) {
        cout << "Error: Result will overflow unsigned long long." << endl;
    }

    cout << input << "! = "
         << factorial(static_cast<unsigned int>(input))
         << endl;

    return 0;
}
