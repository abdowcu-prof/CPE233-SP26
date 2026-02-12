#include <iostream>
using namespace std;

unsigned long long fibonacci(unsigned int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacci(unsigned int current, unsigned int n) {

    if (current > n)
        return;

    cout << fibonacci(current) << " ";

    printFibonacci(current + 1, n);
}

int main() {

    unsigned int n;
    cin >> n;

    printFibonacci(0, n);

    cout << endl;
    return 0;
}
